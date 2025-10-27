import React, { useState, useEffect, useCallback, useMemo } from 'react';

// --- Game Constants ---

// Unit stats: name, attack value (att), defense value (def), and loss priority.
// Lower priority means the unit is lost first (Infantry -> Tank -> Fighter).
const UNIT_STATS = {
    INFANTRY: { name: 'Infantry', att: 1, def: 2, priority: 1, color: 'bg-green-600' },
    TANK: { name: 'Tank', att: 3, def: 3, priority: 2, color: 'bg-yellow-600' },
    FIGHTER: { name: 'Fighter', att: 3, def: 4, priority: 3, color: 'bg-blue-600' },
};

const initialAlliedForce = { INFANTRY: 5, TANK: 1, FIGHTER: 1 };
const initialAxisForce = { INFANTRY: 4, TANK: 2, FIGHTER: 1 };

// Loss priority order (lowest priority first)
const LOSS_ORDER = ['INFANTRY', 'TANK', 'FIGHTER'];

// --- Utility Functions (Translated from C++) ---

const rollD6 = () => (Math.floor(Math.random() * 6) + 1);

const isForceEliminated = (force) => {
    return Object.values(force).every(count => count === 0);
};

/**
 * Simulates one side's combat phase.
 * @param {object} force - The unit counts.
 * @param {boolean} isAttacking - If true, use attack value; otherwise, use defense value.
 * @returns {{hits: number, rolls: string}} - Total hits and a formatted string of rolls.
 */
const resolveCombatPhase = (name, force, isAttacking) => {
    let totalHits = 0;
    let rollsLog = `${name} ${isAttacking ? 'Attacking' : 'Defending'}: `;

    for (const type of LOSS_ORDER) {
        const count = force[type];
        const stats = UNIT_STATS[type];
        const hitValue = isAttacking ? stats.att : stats.def;

        if (count > 0) {
            let unitHits = 0;
            rollsLog += `\n  ${stats.name} x${count} (Hit $\\le$ ${hitValue}): `;
            
            for (let i = 0; i < count; i++) {
                const roll = rollD6();
                if (roll <= hitValue) {
                    unitHits++;
                    rollsLog += `($\\checkmark$${roll}) `;
                } else {
                    rollsLog += `($\\times$${roll}) `;
                }
            }
            rollsLog += `-> Hits: **${unitHits}**`;
            totalHits += unitHits;
        }
    }
    return { hits: totalHits, rolls: rollsLog };
};

/**
 * Modifies the force map by applying losses.
 * @param {object} currentForce - The unit counts (will be modified).
 * @param {number} hitsTaken - The number of casualties to assign.
 * @returns {object} - The modified force and loss log.
 */
const takeLosses = (currentForce, hitsTaken) => {
    let force = { ...currentForce };
    let lossesRemaining = hitsTaken;
    let lossLog = '';

    if (hitsTaken <= 0) return { force, lossLog: 'No losses taken.' };

    lossLog += `Taking ${hitsTaken} losses. \n`;

    for (const type of LOSS_ORDER) {
        if (lossesRemaining <= 0) break;

        const availableUnits = force[type];
        const unitsLost = Math.min(lossesRemaining, availableUnits);

        force[type] -= unitsLost;
        lossesRemaining -= unitsLost;

        if (unitsLost > 0) {
            lossLog += `  - Lost ${unitsLost} ${UNIT_STATS[type].name}. \n`;
        }
    }
    return { force, lossLog };
};

// --- React Component ---

const ForceDisplay = ({ name, force, isAttacker }) => (
    <div className={`p-4 rounded-lg shadow-xl transition-all duration-300 ${isAttacker ? 'bg-gray-800' : 'bg-red-900'} text-white`}>
        <h3 className="text-xl font-bold mb-3 border-b border-white/20 pb-2">
            {name} ({isAttacker ? 'Attacker' : 'Defender'})
        </h3>
        <div className="space-y-2">
            {LOSS_ORDER.map(type => {
                const count = force[type] || 0;
                const stats = UNIT_STATS[type];
                const totalUnits = Object.values(force).reduce((a, b) => a + b, 0);
                const isActive = count > 0;

                return (
                    <div key={type} className={`p-2 rounded flex justify-between items-center ${isActive ? stats.color : 'bg-gray-600/50'} ${isActive ? 'shadow-md' : ''}`}>
                        <span className="font-semibold">{stats.name}:</span>
                        <div className="text-right">
                            <span className="text-lg font-extrabold mr-2">{count}</span>
                            <span className="text-xs opacity-75">
                                (A: {stats.att} / D: {stats.def})
                            </span>
                        </div>
                    </div>
                );
            })}
        </div>
        <div className="mt-4 pt-2 border-t border-white/20 text-xl font-bold">
            Total Units: {Object.values(force).reduce((a, b) => a + b, 0)}
        </div>
    </div>
);


const App = () => {
    const [alliedForce, setAlliedForce] = useState(initialAlliedForce);
    const [axisForce, setAxisForce] = useState(initialAxisForce);
    const [round, setRound] = useState(0);
    const [log, setLog] = useState([]);
    const [battleStatus, setBattleStatus] = useState('Pending'); // Pending, Active, Allied Victory, Axis Victory, Retreat

    const isBattleActive = battleStatus === 'Active';
    const canContinue = isBattleActive && !isForceEliminated(alliedForce) && !isForceEliminated(axisForce);
    const totalUnits = useMemo(() => Object.values(alliedForce).reduce((a, b) => a + b, 0) + Object.values(axisForce).reduce((a, b) => a + b, 0), [alliedForce, axisForce]);

    const resetGame = useCallback(() => {
        setAlliedForce(initialAlliedForce);
        setAxisForce(initialAxisForce);
        setRound(0);
        setLog([]);
        setBattleStatus('Pending');
    }, []);

    const appendLog = useCallback((message) => {
        setLog(prevLog => [`[R${round}] ${message}`, ...prevLog]);
    }, [round]);

    const runCombatRound = useCallback(() => {
        if (!canContinue) return;

        setRound(prev => prev + 1);

        // --- 1. Resolve Combat ---
        const alliedResult = resolveCombatPhase('Allies', alliedForce, true);
        const axisResult = resolveCombatPhase('Axis', axisForce, false);
        
        appendLog(`--- COMBAT RESOLUTION ---`);
        appendLog(`Allies scored **${alliedResult.hits}** hits. Axis scored **${axisResult.hits}** hits.`);
        appendLog(alliedResult.rolls);
        appendLog(axisResult.rolls);
        
        // --- 2. Take Losses ---
        const { force: newAlliedForce, lossLog: alliedLossLog } = takeLosses(alliedForce, axisResult.hits);
        const { force: newAxisForce, lossLog: axisLossLog } = takeLosses(axisForce, alliedResult.hits);
        
        setAlliedForce(newAlliedForce);
        setAxisForce(newAxisForce);
        
        appendLog(`--- LOSSES TAKEN ---`);
        appendLog(`Allies Losses:\n${alliedLossLog}`);
        appendLog(`Axis Losses:\n${axisLossLog}`);

    }, [alliedForce, axisForce, canContinue, appendLog]);

    const handleRetreat = useCallback(() => {
        if (isBattleActive) {
            setBattleStatus('Retreat');
            appendLog(`*** ALLIED FORCES RETREAT *** The battle ends in an Axis Defensive Victory by withdrawal.`);
        }
    }, [isBattleActive, appendLog]);


    // --- Status Check useEffect ---
    useEffect(() => {
        const alliesEliminated = isForceEliminated(alliedForce);
        const axisEliminated = isForceEliminated(axisForce);

        if (round > 0) {
            if (alliesEliminated && axisEliminated) {
                setBattleStatus('Annihilation');
                appendLog(`*** MUTUAL ANNIHILATION! *** No forces remain on the field.`);
            } else if (axisEliminated) {
                setBattleStatus('Allied Victory');
                appendLog(`*** ALLIED MAJOR VICTORY! *** The Axis forces were eliminated.`);
            } else if (alliesEliminated) {
                setBattleStatus('Axis Victory');
                appendLog(`*** AXIS DEFENSIVE VICTORY! *** The Allied forces were eliminated.`);
            }
        }
    }, [alliedForce, axisForce, round, appendLog]);

    // --- Dynamic Status Display ---
    const getStatusText = () => {
        switch (battleStatus) {
            case 'Pending': return { text: 'Ready to Attack', color: 'bg-indigo-600' };
            case 'Active': return { text: `Battle In Progress (Round ${round})`, color: 'bg-blue-600' };
            case 'Allied Victory': return { text: 'ALLIED VICTORY!', color: 'bg-green-600' };
            case 'Axis Victory': return { text: 'AXIS DEFENSIVE VICTORY!', color: 'bg-red-600' };
            case 'Retreat': return { text: 'AXIS VICTORY (Allied Retreat)', color: 'bg-yellow-600' };
            case 'Annihilation': return { text: 'MUTUAL ANNIHILATION', color: 'bg-gray-600' };
            default: return { text: 'Unknown Status', color: 'bg-gray-400' };
        }
    };
    const status = getStatusText();

    return (
        <div className="min-h-screen bg-gray-900 text-gray-100 p-4 font-inter">
            {/* FIX: Removed 'jsx global' attributes which caused React warnings */}
            <style>{`
                /* Simple Scrollbar Styling for Log */
                ::-webkit-scrollbar {
                    width: 8px;
                }
                ::-webkit-scrollbar-thumb {
                    background: #4b5563;
                    border-radius: 4px;
                }
                ::-webkit-scrollbar-track {
                    background: #1f2937;
                }
            `}</style>

            <header className="text-center mb-8">
                <h1 className="text-4xl font-extrabold text-white mb-2">
                    Axis & Allies Tactical Simulator
                </h1>
                <p className="text-gray-400">
                    Simplified Single-Territory Combat (10-Minute Game)
                </p>
            </header>

            {/* Battle Status Indicator */}
            <div className={`p-3 rounded-xl mb-6 shadow-2xl ${status.color} text-center font-bold text-xl uppercase tracking-wider`}>
                {status.text}
            </div>

            {/* Main Layout: Forces & Controls */}
            <div className="grid grid-cols-1 lg:grid-cols-3 gap-6 mb-8">
                {/* 1. Allied Force Display (Left/Top) */}
                <ForceDisplay name="Allied" force={alliedForce} isAttacker={true} />

                {/* 2. Controls (Center) */}
                <div className="flex flex-col space-y-4 p-4 rounded-lg bg-gray-800/80 shadow-2xl">
                    <h3 className="text-2xl font-bold text-center border-b pb-2 border-gray-600 text-yellow-300">
                        Battle Manager
                    </h3>
                    
                    {battleStatus === 'Pending' && (
                        <button
                            onClick={() => setBattleStatus('Active')}
                            className="w-full p-3 bg-green-700 hover:bg-green-600 rounded-lg font-bold text-lg transition duration-200 shadow-lg active:scale-[.98]"
                        >
                            Start Attack
                        </button>
                    )}

                    {canContinue && (
                        <>
                            <button
                                onClick={runCombatRound}
                                className="w-full p-3 bg-blue-700 hover:bg-blue-600 rounded-lg font-bold text-lg transition duration-200 shadow-lg active:scale-[.98]"
                            >
                                Next Combat Round
                            </button>
                            <button
                                onClick={handleRetreat}
                                className="w-full p-3 bg-yellow-600 hover:bg-yellow-500 rounded-lg font-bold text-lg transition duration-200 shadow-lg active:scale-[.98]"
                            >
                                Retreat (0)
                            </button>
                        </>
                    )}
                    
                    {/* Restart/Reset Button */}
                    {battleStatus !== 'Pending' && !canContinue && (
                        <button
                            onClick={resetGame}
                            className="w-full p-3 bg-indigo-700 hover:bg-indigo-600 rounded-lg font-bold text-lg transition duration-200 shadow-lg active:scale-[.98]"
                        >
                            Restart Battle
                        </button>
                    )}
                    
                    {battleStatus !== 'Pending' && (
                        <p className="text-center text-sm text-gray-400">
                            Total Units Engaged: {totalUnits}
                        </p>
                    )}
                </div>

                {/* 3. Axis Force Display (Right/Bottom) */}
                <ForceDisplay name="Axis" force={axisForce} isAttacker={false} />
            </div>

            {/* Combat Log */}
            <div className="mt-8 bg-gray-800/80 p-6 rounded-lg shadow-2xl">
                <h2 className="text-2xl font-bold border-b pb-3 mb-4 border-gray-600 text-cyan-400">
                    Combat Log
                </h2>
                <div className="h-64 overflow-y-auto space-y-3 p-2 text-sm bg-gray-900/50 rounded-md">
                    {log.length === 0 ? (
                        <p className="text-gray-500 text-center mt-8">The battle has not yet begun. Start the attack!</p>
                    ) : (
                        log.map((entry, index) => (
                            <pre 
                                key={index} 
                                className={`whitespace-pre-wrap p-2 rounded-md ${index === 0 ? 'bg-yellow-900/30' : 'bg-gray-700/50'} text-xs leading-relaxed`}
                                dangerouslySetInnerHTML={{ __html: entry.replace(/\\n/g, '<br>').replace(/\*\*(.*?)\*\*/g, '<strong>$1</strong>') }}
                            />
                        ))
                    )}
                </div>
            </div>
        </div>
    );
};

export default App;

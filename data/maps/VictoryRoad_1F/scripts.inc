VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_1F, 100, VictoryRoad_1F_EventScript_SetRockBarrier
	setobjectxyperm LOCALID_VICTORY_ROAD_1F_BOULDER, 20, 16
	goto_if_set FLAG_OPEN_REGI_CAVES, VictoryRoad_1F_EventScript_OpenRegiPath
	end

VictoryRoad_1F_EventScript_OpenRegiPath::
	setmetatile 19, 19, METATILE_Cave_Ground, 0
	setmetatile 19, 20, METATILE_Cave_Ground, 0
	setmetatile 19, 21, METATILE_Cave_WallTop, 1
	setmetatile 20, 19, METATILE_Cave_Ground, 0
	setmetatile 20, 20, METATILE_Cave_Ground, 0
	setmetatile 20, 21, METATILE_Cave_WallTop, 1
	setmetatile 21, 18, METATILE_Cave_SmallRocks, 1
	setmetatile 21, 19, METATILE_Cave_Ground, 0
	setmetatile 21, 20, METATILE_Cave_Ground, 0
	setmetatile 21, 21, METATILE_Cave_WallTop, 1
	setmetatile 22, 18, METATILE_Cave_CornerBottomRight, 1
	setmetatile 22, 19, METATILE_Cave_Ground, 0
	setmetatile 22, 20, METATILE_Cave_Ground, 0
	setmetatile 22, 21, METATILE_Cave_WallTop, 1
	setmetatile 23, 18, METATILE_Cave_WallBottom, 1
	setmetatile 23, 19, METATILE_Cave_Ground, 0
	setmetatile 23, 20, METATILE_Cave_Ground, 0
	setmetatile 23, 21, METATILE_Cave_WallTop, 1
	setmetatile 24, 17, METATILE_Cave_CornerInnerRight, 1
	setmetatile 24, 18, METATILE_Cave_CornerBottomLeft, 1
	setmetatile 24, 19, METATILE_Cave_Ground, 0
	setmetatile 24, 20, METATILE_Cave_Ground, 0
	setmetatile 24, 21, METATILE_Cave_WallTop, 1
	setmetatile 25, 17, METATILE_Cave_WallBottom, 1
	setmetatile 25, 18, METATILE_Cave_Ground, 0
	setmetatile 25, 19, METATILE_Cave_Ground, 0
	setmetatile 25, 20, METATILE_Cave_Ground, 0
	setmetatile 25, 21, METATILE_Cave_WallTop, 1
	setmetatile 26, 17, METATILE_Cave_WallBottom, 1
	setmetatile 26, 18, METATILE_Cave_Ground, 0
	setmetatile 26, 19, METATILE_Cave_Ground, 0
	setmetatile 26, 20, METATILE_Cave_CornerTopRight, 1
	setmetatile 26, 21, METATILE_Cave_WallTopCornerInnerLeft, 1
	setmetatile 27, 17, METATILE_Cave_WallBottom, 1
	setmetatile 27, 18, METATILE_Cave_Ground, 0
	setmetatile 27, 19, METATILE_Cave_Ground, 0
	setmetatile 27, 20, METATILE_Cave_WallTop, 1
	special DrawWholeMapView
	goto_if_unset FLAG_CAUGHT_REGISTEEL, VictoryRoad_1F_EventScript_TestResetRegisteel
	releaseall
	end

VictoryRoad_1F_EventScript_SetRockBarrier::
	setmetatile 12, 14, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 15, METATILE_Cave_RockBarrier_Bottom, 1
	end

VictoryRoad_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VICTORY_ROAD_1F
	end

VictoryRoad_1F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_1F, 100, VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 14, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 15, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_1F_BOULDER
	setvar VAR_MAP_SCENE_VICTORY_ROAD_1F, 100
	goto_if_set FLAG_OPEN_REGI_CAVES, VictoryRoad_1F_EventScript_FloorSwitchRegiOpen
	releaseall
	end

VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_1F_EventScript_FloorSwitchRegiOpen::
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	delay 40
	goto VictoryRoad_1F_EventScript_OpenRegiPath
	return

VictoryRoad_1F_EventScript_Naomi::
	trainerbattle_single TRAINER_COOLTRAINER_NAOMI, VictoryRoad_1F_Text_NaomiIntro, VictoryRoad_1F_Text_NaomiDefeat
	msgbox VictoryRoad_1F_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Rolando::
	trainerbattle_single TRAINER_COOLTRAINER_ROLANDO, VictoryRoad_1F_Text_RolandoIntro, VictoryRoad_1F_Text_RolandoDefeat
	msgbox VictoryRoad_1F_Text_RolandoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Sam::
	trainerbattle_single TRAINER_BUG_CATCHER_VR_SAM, VictoryRoad_1F_Text_SamIntro, VictoryRoad_1F_Text_SamDefeat
	msgbox VictoryRoad_1F_Text_SamPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katie::
	trainerbattle_single TRAINER_BEAUTY_VR_KATIE, VictoryRoad_1F_Text_KatieIntro, VictoryRoad_1F_Text_KatieDefeat
	msgbox VictoryRoad_1F_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Lyn::
	trainerbattle_single TRAINER_BURGLAR_VR_LYN, VictoryRoad_1F_Text_LynIntro, VictoryRoad_1F_Text_LynDefeat
	msgbox VictoryRoad_1F_Text_LynPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Thomas::
	trainerbattle_single TRAINER_BLACK_BELT_VR_THOMAS, VictoryRoad_1F_Text_ThomasIntro, VictoryRoad_1F_Text_ThomasDefeat
	msgbox VictoryRoad_1F_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_TestResetRegisteel::
	goto_if_unset FLAG_REGISTEEL_FLED, VictoryRoad_1F_EventScript_ResetRegisteel
	end

VictoryRoad_1F_EventScript_ResetRegisteel::
	clearflag FLAG_HIDE_REGISTEEL
	end

VictoryRoad_1F_EventScript_Registeel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
	delay 40
	seteventmon SPECIES_REGISTEEL, 40
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_1F_EventScript_DefeatedRegisteel
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_1F_EventScript_RanFromRegisteel
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_1F_EventScript_RanFromRegisteel
	setflag FLAG_CAUGHT_REGISTEEL
	setflag FLAG_HIDE_REGISTEEL
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_REGISTEEL
    fadescreen FADE_FROM_BLACK
	release
	end

VictoryRoad_1F_EventScript_DefeatedRegisteel::
	setflag FLAG_REGISTEEL_FLED
	setvar VAR_0x8004, SPECIES_REGISTEEL
	goto VictoryRoad_1F_EventScript_MonFlewAway
	end

VictoryRoad_1F_EventScript_RanFromRegisteel::
	setflag FLAG_REGISTEEL_FLED
	setvar VAR_0x8004, SPECIES_REGISTEEL
	goto VictoryRoad_1F_EventScript_MonFlewAway
	release
	end

VictoryRoad_1F_EventScript_MonFlewAway::
	setflag FLAG_HIDE_REGISTEEL
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_REGISTEEL
    fadescreen FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway, MSGBOX_AUTOCLOSE
    release
    end

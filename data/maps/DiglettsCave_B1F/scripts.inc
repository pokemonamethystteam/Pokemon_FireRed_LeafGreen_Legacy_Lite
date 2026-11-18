DiglettsCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DiglettsCave_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DiglettsCave_B1F_OnTransition
	.byte 0

DiglettsCave_B1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_DIGLETTS_CAVE_B1F
	end

DiglettsCave_B1F_OnLoad::
	goto_if_set FLAG_OPEN_REGI_CAVES, DiglettsCave_B1F_EventScript_OpenRegiPath
	goto_if_unset FLAG_CAUGHT_REGIROCK, DiglettsCave_B1F_EventScript_TestResetRegirock
	end

DiglettsCave_B1F_EventScript_OpenRegiPath::
	setmetatile 66, 49, METATILE_DiglettsCave_BottomCornerRight, 1
	setmetatile 67, 49, METATILE_DiglettsCave_Ground, 0
	setmetatile 68, 49, METATILE_DiglettsCave_LeftWall, 1
	setmetatile 66, 48, METATILE_DiglettsCave_RightWall, 1
	setmetatile 67, 48, METATILE_DiglettsCave_Ground, 0
	setmetatile 68, 48, METATILE_DiglettsCave_LeftWall, 1
	setmetatile 66, 47, METATILE_DiglettsCave_RightWall, 1
	setmetatile 67, 47, METATILE_DiglettsCave_Ground, 0
	setmetatile 68, 47, METATILE_DiglettsCave_LeftWall, 1
	setmetatile 66, 46, METATILE_DiglettsCave_RightWall, 1
	setmetatile 67, 46, METATILE_DiglettsCave_Ground, 0
	setmetatile 68, 46, METATILE_DiglettsCave_LeftWall, 1
	setmetatile 66, 45, METATILE_DiglettsCave_RightWall, 1
	setmetatile 67, 45, METATILE_DiglettsCave_Ground, 0
	setmetatile 68, 45, METATILE_DiglettsCave_TopCornerLeft, 1
	setmetatile 66, 44, METATILE_DiglettsCave_RightWall, 1
	setmetatile 66, 43, METATILE_DiglettsCave_RightWall, 1
	return

DiglettsCave_B1F_EventScript_TestResetRegirock::
	goto_if_unset FLAG_REGIROCK_FLED, DiglettsCave_B1F_EventScript_ResetRegirock
	end

DiglettsCave_B1F_EventScript_ResetRegirock::
	clearflag FLAG_HIDE_REGIROCK
	end

DiglettsCave_B1F_EventScript_Regirock::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
	delay 40
	seteventmon SPECIES_REGIROCK, 40
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DiglettsCave_B1F_EventScript_DefeatedRegirock
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DiglettsCave_B1F_EventScript_RanFromRegirock
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DiglettsCave_B1F_EventScript_RanFromRegirock
	setflag FLAG_CAUGHT_REGIROCK
	setflag FLAG_HIDE_REGIROCK
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_REGIROCK
    fadescreen FADE_FROM_BLACK
	release
	end

DiglettsCave_B1F_EventScript_DefeatedRegirock::
	setflag FLAG_REGIROCK_FLED
	setvar VAR_0x8004, SPECIES_REGIROCK
	goto DiglettsCave_B1F_EventScript_MonFlewAway
	end

DiglettsCave_B1F_EventScript_RanFromRegirock::
	setflag FLAG_REGIROCK_FLED
	setvar VAR_0x8004, SPECIES_REGIROCK
	goto DiglettsCave_B1F_EventScript_MonFlewAway
	release
	end

DiglettsCave_B1F_EventScript_MonFlewAway::
	setflag FLAG_HIDE_REGIROCK
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_REGIROCK
    fadescreen FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway, MSGBOX_AUTOCLOSE
    release
    end

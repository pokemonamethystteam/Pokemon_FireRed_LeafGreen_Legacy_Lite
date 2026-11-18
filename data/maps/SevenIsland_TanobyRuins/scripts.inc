SevenIsland_TanobyRuins_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SevenIsland_TanobyRuins_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_OnTransition
	.byte 0

SevenIsland_TanobyRuins_OnLoad::
	goto_if_eq VAR_KYOGRE_LOCATION, 2, SevenIsland_TanobyRuins_EventScript_SetUpKyogre
	goto SevenIsland_TanobyRuins_EventScript_SetUpClearKyogre
	end

SevenIsland_TanobyRuins_EventScript_SetUpKyogre::
	goto_if_set FLAG_CAUGHT_KYOGRE, SevenIsland_TanobyRuins_EventScript_SetUpClearKyogre
	goto_if_set FLAG_KYOGRE_FLED, SevenIsland_TanobyRuins_EventScript_SetUpClearKyogre
	clearflag FLAG_HIDE_KYOGRE
	setflag FLAG_HIDE_KYOGRE_NPC
	end

SevenIsland_TanobyRuins_EventScript_SetUpClearKyogre::
	clearflag FLAG_HIDE_KYOGRE_NPC
	setflag FLAG_HIDE_KYOGRE
	end

SevenIsland_TanobyRuins_OnTransition::
	goto_if_eq VAR_KYOGRE_LOCATION, 2, SevenIsland_TanobyRuins_EventScript_TestWeather
	end

SevenIsland_TanobyRuins_EventScript_TestWeather::
	goto_if_set FLAG_CAUGHT_KYOGRE, SevenIsland_TanobyRuins_EventScript_SetUpClearKyogre
	goto_if_set FLAG_KYOGRE_FLED, SevenIsland_TanobyRuins_EventScript_SetUpClearKyogre
	removeobject LOCAL_ID_TANOBY_WITNESS
	setweather WEATHER_DOWNPOUR
	fadenewbgm MUS_SEVII_DUNGEON
	savebgm MUS_SEVII_DUNGEON
	end


SevenIsland_TanobyRuins_EventScript_KyogreTrigger::
	setvar VAR_TEMP_0, 1
	goto_if_ne VAR_KYOGRE_LOCATION, 2,  EventScript_End
	goto_if_set FLAG_KYOGRE_FLED, EventScript_End
	goto_if_set FLAG_CAUGHT_KYOGRE, EventScript_End
	lock
	applymovement LOCAL_ID_KYOGRE_TANOBY, SevenIsland_TanobyRuins_Movement_KyogreApproach
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 3  @ num shakes
	setvar VAR_0x8007, 25  @ shake delay
	special ShakeScreen
	playse SE_PUDDLE
	delay 25
	playse SE_PUDDLE
	delay 25
	playse SE_PUDDLE
	delay 25
	waitmovement 0
	delay 20
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 6  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeScreen
	waitmoncry
	delay 20
	seteventmon SPECIES_KYOGRE, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SevenIsland_TanobyRuins_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SevenIsland_TanobyRuins_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SevenIsland_TanobyRuins_EventScript_DefeatedKyogre
	setflag FLAG_CAUGHT_KYOGRE
	setflag FLAG_HIDE_KYOGRE
    fadescreen FADE_TO_BLACK
    removeobject LOCAL_ID_KYOGRE_TANOBY
    fadescreen FADE_FROM_BLACK
	setweather WEATHER_SUNNY
	doweather
	fadenewbgm MUS_SEVII_ROUTE
	savebgm MUS_SEVII_ROUTE
	release
	end

SevenIsland_TanobyRuins_EventScript_DefeatedKyogre::
	setflag FLAG_KYOGRE_FLED
	setflag FLAG_HIDE_KYOGRE
    fadescreen FADE_TO_BLACK
    removeobject LOCAL_ID_KYOGRE_TANOBY
    fadescreen FADE_FROM_BLACK
	setvar VAR_0x8004, SPECIES_KYOGRE
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway, MSGBOX_AUTOCLOSE
	setweather WEATHER_SUNNY
	doweather
	fadenewbgm MUS_SEVII_ROUTE
	savebgm MUS_SEVII_ROUTE
    release
    end

SevenIsland_TanobyRuins_Movement_KyogreApproach:
	walk_slower_left
	walk_slower_left
	walk_slower_left
	step_end


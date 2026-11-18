PokemonMansion_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_3F_OnTransition
	.byte 0

PokemonMansion_3F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_OnTransition::
	call_if_unset FLAG_CAUGHT_MEW, PokemonMansion_3F_EventScript_ShowMewTest
	setflag FLAG_HIDE_MEW
	end

PokemonMansion_3F_EventScript_ShowMewTest::
	call_if_unset FLAG_MEW_FLED, PokemonMansion_3F_EventScript_ShowMew
	setflag FLAG_HIDE_MEW
	end

PokemonMansion_3F_EventScript_ShowMew::
	clearflag FLAG_HIDE_MEW
	end

PokemonMansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Mew::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setwildbattle SPECIES_MEW, 30
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PokemonMansion_3F_EventScript_DefeatedMew
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PokemonMansion_3F_EventScript_RanFromMew
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PokemonMansion_3F_EventScript_RanFromMew
	setflag FLAG_HIDE_MEW
	setflag FLAG_CAUGHT_MEW
	release
	end

PokemonMansion_3F_EventScript_DefeatedMew::
	setflag FLAG_HIDE_MEW
	setflag FLAG_MEW_FLED
	goto EventScript_RemoveStaticMon
	end

PokemonMansion_3F_EventScript_RanFromMew::
	setvar VAR_0x8004, SPECIES_MEW
	goto EventScript_MonFlewAway
	end

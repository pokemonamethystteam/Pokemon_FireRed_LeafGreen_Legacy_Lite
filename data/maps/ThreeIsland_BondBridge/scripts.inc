ThreeIsland_BondBridge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BondBridge_OnTransition
	.byte 0

ThreeIsland_BondBridge_OnTransition::
	call_if_unset FLAG_SYS_CAN_LINK_WITH_RS, ThreeIsland_BondBridge_EventScript_ClearBlue
	end

ThreeIsland_BondBridge_EventScript_ClearBlue::
	setflag FLAG_HIDE_BLUE_THREEISLAND
	setflag FLAG_CELEBI_FLED
	removeobject LOCALID_BLUE_THREEISLAND
	return

ThreeIsland_BondBridge_EventScript_BlueTriggerNorth::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_HIDE_BLUE_THREEISLAND, EventScript_End
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_BLUE_THREEISLAND, ThreeIsland_BondBridge_Movement_Blue_North
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto ThreeIsland_BondBridge_EventScript_Blue
	releaseall
	end

ThreeIsland_BondBridge_EventScript_BlueTriggerSouth::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_HIDE_BLUE_THREEISLAND, EventScript_End
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_BLUE_THREEISLAND, ThreeIsland_BondBridge_Movement_Blue_South
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto ThreeIsland_BondBridge_EventScript_Blue
	releaseall
	end

ThreeIsland_BondBridge_EventScript_Blue::
	msgbox ThreeIsland_BondBridge_Text_BlueCelebiHint, MSGBOX_NPC
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_BLUE_THREEISLAND, ThreeIsland_BondBridge_Movement_Blue_Exit
	waitmovement 0
	setflag FLAG_HIDE_BLUE_THREEISLAND 
	clearflag FLAG_CELEBI_FLED
	removeobject LOCALID_BLUE_THREEISLAND
	fadedefaultbgm
	releaseall
	end

ThreeIsland_BondBridge_Movement_Blue_North:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

ThreeIsland_BondBridge_Movement_Blue_South:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end

ThreeIsland_BondBridge_Movement_Blue_Exit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ThreeIsland_BondBridge_EventScript_BerryForestSign::
	msgbox ThreeIsland_BondBridge_Text_BerryForestAhead, MSGBOX_SIGN
	end

ThreeIsland_BondBridge_EventScript_BondBridgeSign::
	msgbox ThreeIsland_BondBridge_Text_BondBridgeSign, MSGBOX_SIGN
	end

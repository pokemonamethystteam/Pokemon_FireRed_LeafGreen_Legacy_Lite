CeladonCity_DepartmentStore_5F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_5F_Text_Drugstore, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_TMS
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_TMS::
	.2byte ITEM_TM01_FOCUS_PUNCH
	.2byte ITEM_TM02_DRAGON_CLAW
	.2byte ITEM_TM03_WATER_PULSE
	.2byte ITEM_TM09_BULLET_SEED
	.2byte ITEM_TM10_HIDDEN_POWER
	.2byte ITEM_TM21_FRUSTRATION
	.2byte ITEM_TM27_RETURN
	.2byte ITEM_TM28_DIG
	.2byte ITEM_TM31_BRICK_BREAK
	.2byte ITEM_TM34_SHOCK_WAVE
	.2byte ITEM_TM36_SLUDGE_BOMB
	.2byte ITEM_TM39_ROCK_TOMB
	.2byte ITEM_TM40_AERIAL_ACE
	.2byte ITEM_TM42_FACADE
	.2byte ITEM_TM43_SECRET_POWER
	.2byte ITEM_TM46_THIEF
	.2byte ITEM_TM47_STEEL_WING
	.2byte ITEM_TM50_OVERHEAT
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_Vitamins
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_Vitamins::
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CALCIUM
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_NONE
	release
	end

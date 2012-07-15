#pragma once
#include "../Defines.h"

class cWorld;
class cPlayer;


class cItemHandler
{
public:
	cItemHandler(int a_ItemID);
	virtual bool OnItemUse(cWorld *a_World, cPlayer *a_Player, cItem *a_Item, int a_X, int a_Y, int a_Z, char a_Dir);	//eg for fishing or hoes
	virtual bool OnDiggingBlock(cWorld *a_World, cPlayer *a_Player, cItem *a_Item, int a_X, int a_Y, int a_Z, char a_Dir);
	virtual void OnBlockDestroyed(cWorld *a_World, cPlayer *a_Player, cItem *a_Item, int a_X, int a_Y, int a_Z);
	virtual void OnFoodEaten(cWorld *a_World, cPlayer *a_Player, cItem *a_Item);
	virtual int GetMaxStackSize();
	virtual int GetMaxDamage();

	virtual void PlaceBlock(cWorld *a_World, cPlayer *a_Player, cItem *a_Item, int a_X, int a_Y, int a_Z, char a_Dir);
	
	virtual bool IsTool();
	virtual bool IsFood();
	//Blocks simply get placed
	virtual bool IsPlaceable();

	virtual BLOCKTYPE GetBlockType();
	virtual char GetBlockMeta(char a_ItemMeta);

	virtual bool CanHarvestBlock(BLOCKTYPE a_BlockID);

	static cItemHandler *GetItemHandler(int a_ItemID);

	static void Deinit();

	
protected:
	int m_ItemID;
	static cItemHandler *CreateItemHandler(int m_ItemID);

	static cItemHandler *m_ItemHandler[2266];
	static bool m_HandlerInitialized;	//used to detect if the itemhandlers are initialized
};

//Short function
inline cItemHandler *ItemHandler(int a_ItemID) { return cItemHandler::GetItemHandler(a_ItemID); }
#include "lib.h"
#include "libMacros.h"
#include "MngArcanaRPG.h"
#include "MngArcanaRPGItems.h"


CRPGArcana::CRPGArcana()
{
	SetMaxEntities(3);
	AddEntity(new CRPGEntity("ENTITYRooks", 10, 10, 10, 10, 10, 0, 0, 150, 30, 150, 30, 99, 4, 5, 0));
	AddEntity(new CRPGEntity("ENTITYSylph", 10, 10, 10, 10, 10, 0, 0, 150, 30, 150, 30, 99, 4, 5, 0));
	AddEntity(new CRPGEntity("ENTITYTeefa", 10, 10, 10, 10, 10, 0, 0, 150, 30, 150, 30, 99, 4, 5, 0));

	SetMaxItems(15);
	AddItem(new CRPGItemHerbs(15, "ITEMHerbs"));
	AddItem(new CRPGItemMedicine(70, "ITEMMedicine"));
	AddItem(new CRPGItemSleepingBag(500, "ITEMSleepingBag"));
	AddItem(new CRPGItemReturnRing(100, "ITEMReturnRing"));
	AddItem(new CRPGItemSilverFlask(100, "ITEMSilverFlask"));
	AddItem(new CRPGItemRestoreHoney(3000, "ITEMRestoreHoney"));
	AddItem(new CRPGItemMPHoney(3200, "ITEMMPHoney"));
	AddItem(new CRPGItemTent(1000, "ITEMTent"));
	AddItem(new CRPGItemStrengthHoney(3000, "ITEMStrengthHoney"));
	AddItem(new CRPGItemIntelligenceHoney(3000, "ITEMIntelligenceHoney"));
	AddItem(new CRPGItemEnduranceHoney(3000, "ITEMEnduranceHoney"));
	AddItem(new CRPGItemUsable(1, GET_STRING("ITEMWater"), "ITEMWater"));
	AddItem(new CRPGItemElixir(5, "ITEMElixir"));
	AddItem(new CRPGItemFoodA(10, "ITEMFoodA"));
	AddItem(new CRPGItemFoodB(20, "ITEMFoodB"));

}

CRPGArcana::~CRPGArcana()
{


}

















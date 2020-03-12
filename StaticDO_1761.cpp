#include <iostream>
#include <stdio.h>
#include "compatibility.h"
#include "bdaqctrl.h"
#include <sstream>
#include <cstdlib>
#include "BDaqCtrl.h"
#include <stdio.h>
#include <dos.h>
#include <windows.h>

using namespace std;
/////////////////////////////////////////////////////////
#define  deviceDescription  L"PCI-1761,BID#0"
using namespace Automation::BDaq;
InstantDoCtrl * instantDoCtrl = InstantDoCtrl::Create();

int main()
{
	setlocale(LC_ALL, "Rus");
	ErrorCode ret = Success;
	InstantDoCtrl * instantDoCtrl = AdxInstantDoCtrlCreate();
	DeviceInformation devInfo(deviceDescription);
	ret = instantDoCtrl->setSelectedDevice(devInfo);

	// Read profile to configure device
	//ret = instantDoCtrl->LoadProfile(filePath);

	ICollection<PortDirection>* portDirection = instantDoCtrl->getPortDirection();
	if (portDirection != NULL)
	{
		//Set the first two port to output 
		DioPortDir dir =Output;
		portDirection->getItem(0).setDirection(dir);
	}
	else
	{
		printf("There is no DIO port of the selected device can set direction!\n");
	}

	ret = instantDoCtrl->Write(0, byte(0));

	int8 state;
	int8 portData;
	int  a    = 0;
	int  key  = 0;
	int  sost = 0;
	int  i[9][1] = { 1,1,1,1,1,1,1,1,1 };
	unsigned char  bit[1];
	char           state_key [2][4]	 = { "ON", "OFF"};
	byte bufferForReading[1] = { 0 };
	while (true)
	{
		sost = instantDoCtrl->Read(0, 1, bufferForReading);

		printf("name_1				 - 1	name_9 - %s  \n"				, state_key[*i[0]]);
		printf("name_2				 - 2	name_10	- %s \n"				, state_key[*i[1]]);
		printf("name_3				 - 3	name_11	- %s \n"				, state_key[*i[2]]);
		printf("name_4				 - 4	name_12	- %s		Sost = %x\n", state_key[*i[3]], bufferForReading[0]);
		printf("name_5				 - 5	name_13	- %s \n"				, state_key[*i[4]]);
		printf("name_6				 - 6	name_14	- %s \n"				, state_key[*i[5]]);
		printf("name_7				 - 7	name_15	- %s \n"				, state_key[*i[6]]);
		printf("name_8				 - 8	name_16 - %s \n"				, state_key[*i[7]]);
		printf("exit				 - 0				 \n");

		scanf("%i", &key);
		switch (key)
		{
		case 1:
			//----------------------1
			sost = instantDoCtrl->ReadBit(0, 0, &bit[0]);
			if (bit[0] == 0)
			{
				ret = instantDoCtrl->WriteBit(0, 0, 1);
				i[0][0] = 0;
			}
			else
			{
				ret = instantDoCtrl->WriteBit(0, 0, 0);
				i[0][0] = 1;
			}
			system("cls");
			break;
		case 2:
			//----------------------2
			sost = instantDoCtrl->ReadBit(0, 1, &bit[0]);
			if (bit[0] == 0)
			{
				ret = instantDoCtrl->WriteBit(0, 1, 1);
				i[1][0] = 0;
			}
			else
			{
				ret = instantDoCtrl->WriteBit(0, 1, 0);
				i[1][0] = 1;
			}
			system("cls");
			break;
		case 3:
			//----------------------3
			sost = instantDoCtrl->ReadBit(0, 2, &bit[0]);
			if (bit[0] == 0)
			{
				ret = instantDoCtrl->WriteBit(0, 2, 1);
				i[2][0] = 0;
			}
			else
			{
				ret = instantDoCtrl->WriteBit(0, 2, 0);
				i[2][0] = 1;
			}
			system("cls");
			break;
		case 4:
			//----------------------4
			sost = instantDoCtrl->ReadBit(0, 3, &bit[0]);
			if (bit[0] == 0)
			{
				ret = instantDoCtrl->WriteBit(0, 3, 1);
				i[3][0] = 0;
			}
			else
			{
				ret = instantDoCtrl->WriteBit(0, 3, 0);
				i[3][0] = 1;
			}
			system("cls");
			break;
		case 5:
			//----------------------5
			sost = instantDoCtrl->ReadBit(0, 4, &bit[0]);
			if (bit[0] == 0)
			{
				ret = instantDoCtrl->WriteBit(0, 4, 1);
				i[4][0] = 0;
			}
			else
			{
				ret = instantDoCtrl->WriteBit(0, 4, 0);
				i[4][0] = 1;
			}
			system("cls");
			break;
		case 6:
			//----------------------6
			sost = instantDoCtrl->ReadBit(0, 5, &bit[0]);
			if (bit[0] == 0)
			{
				ret = instantDoCtrl->WriteBit(0, 5, 1);
				i[5][0] = 0;
			}
			else
			{
				ret = instantDoCtrl->WriteBit(0, 5, 0);
				i[5][0] = 1;
			}
			system("cls");
			break;
		case 7:
			//----------------------7
			sost = instantDoCtrl->ReadBit(0, 6, &bit[0]);
			if (bit[0] == 0)
			{
				ret = instantDoCtrl->WriteBit(0, 6, 1);
				i[6][0] = 0;
			}
			else
			{
				ret = instantDoCtrl->WriteBit(0, 6, 0);
				i[6][0] = 1;
			}
			system("cls");
			break;
		case 8:
			//----------------------8
			sost = instantDoCtrl->ReadBit(0, 7, &bit[0]);
			if (bit[0] == 0)
			{
				ret = instantDoCtrl->WriteBit(0, 7, 1);
				i[7][0] = 0;
			}
			else
			{
				ret = instantDoCtrl->WriteBit(0, 7, 0);
				i[7][0] = 1;
			}
			system("cls");
			break;
		case 0:
			//----------------------0
			return -1;
		}
	}
}
//ret = instantDoCtrl->Read(portNum, &portData);

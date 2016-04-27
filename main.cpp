#include <iostream>
#include "myShop.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    MyShop shop = MyShop();
    ifstream inFile;
    string data;
    inFile.open("shopItems.txt");
    if (inFile.good())
    {
        int index=0;
        int number=1;
        while(getline(inFile, data))
        {
            string title; int attribute; int cost; int quantity;
            string data2;
            stringstream text(data);
            while(getline(text, data2, ','))
            {
                if (number==1)
                {

                    title = data2; ///For strings
                    number++;
                }
                else if (number==2)
                {
                    istringstream(data2)>>attribute;  ///converts number to string
                    number++;
                }
                else if (number==3)
                {
                    istringstream(data2)>>cost;

                    number++;
                }

                else if (number==4)
                {
                    istringstream(data2)>>quantity;
                    number=1;
                }

            }
            shop.addShopNode(title, attribute, cost, quantity);
            index++;
        }
    }

    else
        cout<<"file unsuccessfully opened"<<endl;
    inFile.close();


    ifstream newFile;
    string playerData;
    newFile.open("playerItems.txt");
    if (newFile.good())
    {
        int playerIndex=0;
        int playerNumber=1;
        while(getline(newFile, playerData))
        {
            string itemName; int itemAttribute; int itemCost; int itemQuantity;
            string playerData2;
            stringstream plyaerText(playerData);
            while(getline(plyaerText, playerData2, ','))
            {
                if (playerNumber==1)
                {

                    itemName = playerData2; ///For strings
                    playerNumber++;
                }
                else if (playerNumber==2)
                {
                    istringstream(playerData2)>>itemAttribute;  ///converts number to string
                    playerNumber++;
                }
                else if (playerNumber==3)
                {
                    istringstream(playerData2)>>itemCost;

                    playerNumber++;
                }

                else if (playerNumber==4)
                {
                    istringstream(playerData2)>>itemQuantity;
                    playerNumber=1;
                }

            }
            shop.addPlayerNode(itemName, itemAttribute, itemCost, itemQuantity);
            playerIndex++;
        }
    }

    else
        cout<<"file unsuccessfully opened"<<endl;
    newFile.close();


    int n=0;
    while (n==0)
    {
        int choice;
        cout<<"======Welcome to Adventurer's Shop======\n"
        "1. Print Shop's Inventory List\n"
        "2. Print Player Inventory List\n"
        "3. Buy an Item\n"
        "4. Sell an Item\n"
        "5. Item Description\n"
        "6. Quit!"<<endl;

        cin>>choice;
        cin.ignore(1000, '\n');

        switch (choice)
        {
        case 1:
            {
                shop.printShopInventory();
                break;

            }
        case 2:
            {
                shop.printPlayerInventory();
                break;

            }
        case 3:
            {
                string title;
                cout<<"Enter item you wish to purchase: (item name, item attribute, item cost)"<<endl;
                getline(cin, title);
                int playerIndex=0;
                int playerNumber=1;
                string itemName;
                int itemAttribute; int itemCost; int itemQuantity;
                string playerData2;
                stringstream playerText(title);
            while(getline(playerText, playerData2, ','))
            {
                if (playerNumber==1)
                {

                    itemName = playerData2; ///For strings
                    playerNumber++;
                }
                else if (playerNumber==2)
                {
                    istringstream(playerData2)>>itemAttribute;  ///converts number to string
                    playerNumber++;
                }
                else if (playerNumber==3)
                {
                    istringstream(playerData2)>>itemCost;

                    playerNumber++;
                }

                else if (playerNumber==4)
                {
                    istringstream(playerData2)>>itemQuantity;
                    playerNumber=1;
                }

            }
                playerIndex++;
                shop.buyItem(itemName, itemAttribute, itemCost, itemQuantity);
                //shop.addPlayerInventory(title, itemAttribute, itemCost, itemQuantity);
                break;
            }
        case 4:
            {
                string title;
                cout<<"Enter Item You Wish to Sell:"<<endl;
                getline(cin, title);
                shop.sellItem(title);
                break;
            }
        case 5:
            {
                string title;
                cout<<"Enter item name for description:"<<endl;
                getline(cin, title);
                shop.itemDescription(title);
                break;

            }
        case 6:
            {
                cout<<"Goodbye!"<<endl;
                n++;
                return 0;
                break;

            }

        }

    }
}







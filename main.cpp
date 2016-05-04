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


    string decision;
    while (decision!="7")
    {
        string choice;
        cout<<"======Welcome to Adventurer's Shop======\n"
        "1. Print Shop's Inventory List\n"
        "2. Print Player Inventory List\n"
        "3. Item Description\n"
        "4. Sell an Item\n"
        "5. Buy an Item\n"
        "6. Player's Current Balance\n"
        "7. Quit!"<<endl;
        getline(cin,decision);
        if (decision != "1" && decision != "2" && decision != "3" && decision != "4"&& decision != "5"&& decision != "6"&& decision != "7") {
            cout << "" << endl;
            cout << "Please Select a number 1-7" << endl;
            cout << "" << endl;
        }


        //cin.ignore(1000, '\n');

       // switch (choice)
        {
        if(decision == "1")
            {
                shop.printShopInventory();
                //break;

            }
        if(decision == "2")
            {
                shop.printPlayerInventory();
                //break;

            }
        if(decision == "5")
            {
                string title;
                cout<<"Enter item you wish to purchase:\n(item name, item attribute, item cost, item quantity)\n(Cool Helmet, 15, 30, 1)"<<endl;
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
                //break;
            }
        if(decision == "4")
            {
                string title;
                cout<<"Enter Item You Wish to Sell:"<<endl;
                getline(cin, title);
                shop.sellItem(title);
                //break;
            }
        if(decision == "3")
            {
                string title1;
                cout<<"Enter item name for description:"<<endl;
                getline(cin, title1);
                shop.itemDescription(title1);
                cout<<"Enter item name for description:"<<endl;
                //break;

            }
        if(decision == "6")
            {

                shop.printPlayerMoney();
                //break;

            }
        if(decision == "7")
            {
                cout<<"Goodbye!"<<endl;
                //descision++;
                //return 0;
                //break;

            }

        }

    }
   //return 0;
}

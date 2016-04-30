#include "myShop.h"
#include <sstream>


using namespace std;

MyShop::MyShop()
{
    //ctor
    root=NULL;
}

MyShop::~MyShop()
{
    DeleteAll(root);
}

///Deletes all the nodes after you quit the game////////////////
void MyShop::DeleteAll(ShopNode* node)
{
    if (node->leftChild!=NULL)
		DeleteAll(node->leftChild);
	if (node->rightChild!=NULL)
		DeleteAll(node->rightChild);
	//cout<<"Deleting: "<<node->title<<endl;
	delete node;
}
///1/////////////////////////////////////////////////////////



///ADDs the initial nodes into the tree, we get the items from the text file/////////////////////
void MyShop::addShopNode(std::string title, int attribute, int cost, int quantity)
{
    ShopNode* tmp=root;
    ShopNode* parent=NULL;
    ShopNode* node=new ShopNode(title, attribute, cost, quantity);
    node->title=title;
    node->leftChild=NULL;
    node->rightChild=NULL;
    while (tmp!=NULL)
    {
        parent=tmp;
        if (node->title.compare(tmp->title)>0)
            tmp=tmp->rightChild;
        else if (node->title.compare(tmp->title)<0)
            tmp=tmp->leftChild;
    }
    if (root==NULL)
        root=node;
    else if (node->title.compare(parent->title)<0)
    {
        parent->leftChild=node;
        node->parent=parent;
    }
    else
    {
        parent->rightChild=node;
        node->parent=parent;
    }
}
///1//////////////////////////////////////////////////////////////

///Adds the player inventory Initialize///////////////////////////////////////////////////////////////////
void MyShop::addPlayerNode(std::string itemName, int itemAttribute, int itemCost, int itemQuantity)
{
    int userquantity = 0;
    PlayerNode* tmp=playerRoot;
    PlayerNode* parent=NULL;
    PlayerNode* node=new PlayerNode(itemName, itemAttribute, itemCost, itemQuantity);
    node->itemName=itemName;
    node->leftChild=NULL;
    node->rightChild=NULL;
    while (tmp!=NULL)
    {
        parent=tmp;
        if (node->itemName.compare(tmp->itemName)>0)
            tmp=tmp->rightChild;
        else if (node->itemName.compare(tmp->itemName)<0)
            tmp=tmp->leftChild;
    }
    if (playerRoot==NULL)
        playerRoot=node;
    else if (node->itemName.compare(parent->itemName)<0)
    {
        parent->leftChild=node;
        node->parent=parent;
    }
    else
    {
        parent->rightChild=node;
        node->parent=parent;
    }
}
/////////////////////////////////////////////////////////////////////////////////


///Adds the item into the players inventory after buying it from shop/////////////
void MyShop::addPlayerInventory(std::string itemName, int itemAttribute, int itemCost, int quantity){
        addPlayerNode(itemName, itemAttribute, itemCost, quantity);
        cout<< "Player has bought " << itemName << " for " << itemCost << " gp" <<endl;



}
///1/////////////////////////////////////////////////////////////////////


///Sells items back to the shop///////////////////////////////////
void MyShop::sellItem(std::string title){
    ShopNode* node=root;
    bool found;
	while (node!=NULL)
	{
		if (node->title.compare(title)>0)
			node=node->leftChild;
		else if (node->title.compare(title)<0)
			node=node->rightChild;
		else if (node->title==title)
        {
            found=true;
            break;
        }
        else
        {
            found=false;
            break;
        }
	}

	if (found==true)
    {
        cout<< endl;
        cout<<node->title << " has been sold!"<<endl;
        node->quantity++;
        cout<<"==========="<<endl;
        cout<<"|Item info|"<<endl;
        cout<<"==========="<<endl;
        cout<<"Item: "<<node->title<<endl;
        cout<<"cost: "<<node->cost<<endl;
        cout<<"Quantity: "<<node->quantity<<endl;
        cout<<"==========="<<endl;
        cout<< endl;

    }
    else if (found==false){
        cout<<"Item not found."<<endl;
        cout<<"Please only type in items that are in the list"<<endl;
    }

}
///////////////////////////////////////////////////////////////////////


///Finds a specific item in the shop, giving details about it////////////////
void MyShop::itemDescription(std::string title)
{
    ShopNode* node=root;
    bool found;
	while (node!=NULL)
	{
		if (node->title.compare(title)>0)
			node=node->leftChild;
		else if (node->title.compare(title)<0)
			node=node->rightChild;
		else if (node->title==title)
        {
            found=true;
            break;
        }
        else
        {
            found=false;
            break;
        }
	}
	if (found==true)
    {
        cout<< endl;
        cout<<"==========="<<endl;
        cout<<"Item Info"<<endl;
        cout<<"==========="<<endl;
        cout<<"Item: "<<node->title<<endl;
        cout<<"Attribute: +"<<node->attribute<<endl;
        cout<<"Cost: "<<node->cost<<" gp"<<endl;
        cout<<"Quantity: "<< node->quantity<<endl;
        cout<<"==========="<<endl;
        cout<< endl;
    }
    /*
    if (found==false)
        cout<<"Item not found."<<endl;
        */
}
/////////////////////////////////////////////////////////////


void MyShop::itemDescriptionPlayer(std::string title)
{
    PlayerNode* node=playerRoot;
    bool found;
	while (node!=NULL)
	{
		if (node->itemName.compare(title)>0)
			node=node->leftChild;
		else if (node->itemName.compare(title)<0)
			node=node->rightChild;
		else if (node->itemName==title)
        {
            found=true;
            break;
        }
        else
        {
            found=false;
            break;
        }
	}
	if (found==true)
    {
        cout<< endl;
        cout<<"==========="<<endl;
        cout<<"Item Info"<<endl;
        cout<<"==========="<<endl;
        cout<<"Item: "<<node->itemName<<endl;
        cout<<"Attribute: +"<<node->itemAttribute<<endl;
        cout<<"Cost: "<<node->itemCost<<" gp"<<endl;
        cout<<"Quantity: "<< node->itemQuantity<<endl;
        cout<<"==========="<<endl;
        cout<< endl;
    }
    /*
    if (found==false)
        cout<<"Item not found."<<endl;
        */
}

///Buys item from the shop/////////////////////////////////////
void MyShop::buyItem(std::string title, int itemAttribute, int itemCost, int itemQuantity)
{
    ShopNode* node=root;
    bool found;
	while (node!=NULL)
	{
		if (node->title.compare(title)>0)
			node=node->leftChild;
		else if (node->title.compare(title)<0)
			node=node->rightChild;
		else if ((node->title==title) && (node->attribute == itemAttribute) && (node->cost == itemCost))
        {
            found=true;
            break;
        }
        else
        {
            found=false;
            break;
        }
	}

	if (found==true) //&& node->quantity!=0
    {
        cout<< endl;
        cout<<node->title << " has been sold!"<<endl;
        node->quantity--;
        cout<<"==========="<<endl;
        cout<<"Item info"<<endl;
        cout<<"==========="<<endl;
        cout<<"Item: "<<node->title<<endl;
        cout<<"cost: "<<node->cost<<endl;
        cout<<"Quantity: "<<node->quantity<<endl;
        cout<<"==========="<<endl;
        cout<< endl;
        if(node->quantity != 0){
        int quantity=1;
        addPlayerInventory(title, itemAttribute, itemCost, quantity);
        }
    }
    else if (found==true && node->quantity==0)
    {
        cout<< endl;
        cout<< node->title<< " x 0" <<endl;
        cout<< "Unfortunately We Are Out Of " << node->title <<endl;
        cout<< endl;
    }
    else if (found==false){
        cout<<"Item not found."<<endl;
    }

}
///////////////////////////////////////////////////////////////////////


///Prints out the inventory in the store(Helper)/////////////////////////////////
void MyShop::printShopInventory()
{
    cout<<endl;
    cout<<"========================"<<endl;
    cout<<"Items In The Shop"<<endl;
    cout<<"========================"<<endl;
    printShopInventory(root);
    cout<<"========================"<<endl;
    cout<<endl;
}
///1//////////////////////////////////////////////////////////////////


///Prints out inventory////////////////////////////////////////////
void MyShop::printShopInventory(ShopNode* node)
{

    if (node->leftChild!=NULL){
        printShopInventory(node->leftChild);
    }
    if (node->rightChild!=NULL){
        printShopInventory(node->rightChild);
    }
    cout<< "- " <<node->title<<" x "<<node->quantity<<endl;
}
///1/////////////////////////////////////////////////////////

///Print Player Inventory//////////////////////////////////
void MyShop::printPlayerInventory()
{
    cout<<endl;
    cout<<"========================"<<endl;
    cout<<"Items In Your Inventory"<<endl;
    cout<<"========================"<<endl;
    printPlayerInventory(playerRoot);
    cout<<"========================"<<endl;
    cout<<endl;
}
///1////////////////////////////////////////////////////////

///Prints the players Inventory!!!/////////////////////////
void MyShop::printPlayerInventory(PlayerNode* node)
{

    if (node->leftChild!=NULL){
        printPlayerInventory(node->leftChild);
    }
    if (node->rightChild!=NULL){
        printPlayerInventory(node->rightChild);
    }
    cout<< "- " <<node->itemName<<" x "<<node->itemQuantity<<endl;
}
///1///////////////////////////////////////////////////////////






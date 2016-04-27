#ifndef MYSHOP_H
#define MYSHOP_H
#include <iostream>

struct ShopNode{
    int attribute;
    std::string title;
    int cost;
    int quantity;

    ShopNode *parent;
    ShopNode *leftChild;
    ShopNode *rightChild;

    ShopNode(){};

    ShopNode(std::string in_title, int in_attribute, int in_cost, int in_quantity)
    {
        title = in_title;
        quantity = in_quantity;
        attribute = in_attribute;
        cost = in_cost;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

struct PlayerNode{
    int itemAttribute;
    std::string itemName;
    int itemCost;
    int itemQuantity;

    PlayerNode *parent;
    PlayerNode *leftChild;
    PlayerNode *rightChild;

    PlayerNode(){};

    PlayerNode(std::string in_title, int in_attribute, int in_cost, int in_quantity)
    {
        itemName = in_title;
        itemQuantity = in_quantity;
        itemAttribute = in_attribute;
        itemCost = in_cost;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class MyShop
{

    public:
        MyShop();
        ~MyShop();
        void printShopInventory();
        void printPlayerInventory();
        void sellItem(std::string itemName);
        void addShopNode(std::string title, int attribute, int cost, int quantity);
        void addPlayerNode(std::string itemName, int itemAttribute, int itemCost, int itemQuantity);
        void itemDescription(std::string title);
        void buyItem(std::string title, int itemAttribute, int itemCost, int itemQuantity);
        void addPlayerInventory(std::string itemName, int itemAttribute, int itemCost, int itemQuantity);



    protected:

    private:
        void DeleteAll(ShopNode * node); //use this for the post-order traversal deletion of the tree
        void printShopInventory(ShopNode* node);
        void printPlayerInventory(PlayerNode* node);
        ShopNode* search(std::string title);
        //MovieNode* treeMinimum(MovieNode *node);
        ShopNode *root;
        PlayerNode *playerRoot;
};

#endif // MOVIETREE_H

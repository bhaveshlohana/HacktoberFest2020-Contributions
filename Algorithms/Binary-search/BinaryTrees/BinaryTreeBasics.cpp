#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *lcl;
    Node *rcl;

public:
    Node *createBT(Node *, int, string);
    void display(Node *, int);
    void inorder(Node *);
    void preorder(Node *);
    void postorder(Node *);
    void levelorder(Node *);
    void parentNode(Node *, int);
    void searchElement(Node *, int);
    void reverseLevelOrder(Node *);
    void spiralLevelOrder(Node *);
    int countLeaf(Node *);
    int heightOfTree(Node *, int);
    bool checkMirror(Node *, Node *);
    Node *getMirror(Node *, Node *);
    int findMin(Node *);
    int findMax(Node *);
    bool ancestorsOfNode(Node *, int);

};

int Node::diameterOfTree(Node *start)
{
    int l, r;
}

bool Node::ancestorsOfNode(Node *start, int item)
{
    if (!start)
        return false;
    if (start->data == item)
        return true;
    if (ancestorsOfNode(start->lcl, item) || ancestorsOfNode(start->rcl, item))
    {
        cout << " " << start->data << " ";
        return true;
    }
}

int Node::findMin(Node *start)
{
    if (!start)
        return INT_MAX;
    int l, r, res = start->data;
    l = findMin(start->lcl);
    r = findMin(start->rcl);
    return (l > r) ? min(r, res) : min(l, res);
}

int Node::findMax(Node *start)
{
    if (!start)
        return INT_MIN;
    int l, r, res = start->data;
    l = findMax(start->lcl);
    r = findMax(start->rcl);
    return (l > r) ? max(l, res) : max(r, res);
}

bool Node::checkMirror(Node *s1, Node *s2)
{
    if (!s1 && !s2)
        return true;
    else if ((!s1 && s2) || (s1 && !s2))
        return false;
    if (checkMirror(s1->lcl, s2->rcl) && checkMirror(s1->rcl, s2->lcl) && s1->data == s2->data)
    {
        return true;
    }
    return false;
}

Node *Node::getMirror(Node *start, Node *newNode)
{
    if (!start)
        return NULL;

    newNode = new Node();
    newNode->data = start->data;
    if (start->lcl)
        newNode->lcl = getMirror(start->lcl, newNode);
    if (start->rcl)
        newNode->rcl = getMirror(start->rcl, newNode);
    Node *temp = newNode->lcl;
    newNode->lcl = newNode->rcl;
    newNode->rcl = temp;
    return newNode;
}

int Node::heightOfTree(Node *start, int level)
{
    if (!start->lcl && !start->rcl)
    {
        return level;
    }
    int j = 0, k = 0;
    if (start->lcl)
    {
        j = heightOfTree(start->lcl, level + 1);
    }
    if (start->rcl)
    {
        k = heightOfTree(start->rcl, level + 1);
    }
    return max(j, k);
}

int Node ::countLeaf(Node *start)
{
    if (!start->lcl && !start->rcl)
    {
        return 1;
    }
    int j = 0, k = 0;
    if (start->lcl)
    {
        j = countLeaf(start->lcl);
    }
    if (start->rcl)
    {
        k = countLeaf(start->rcl);
    }
    return j + k;
}

void Node::spiralLevelOrder(Node *start)
{
    stack<Node *> s1, s2;
    s1.push(start);
    Node *cur;
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            cur = s1.top();
            s1.pop();
            cout << cur->data << " ";

            if (cur->lcl)
                s2.push(cur->lcl);
            if (cur->rcl)
                s2.push(cur->rcl);
        }

        while (!s2.empty())
        {
            cur = s2.top();
            s2.pop();
            cout << cur->data << " ";

            if (cur->rcl)
                s1.push(cur->rcl);
            if (cur->lcl)
                s1.push(cur->lcl);
        }
    }
    cout << endl;
}

void Node::reverseLevelOrder(Node *start)
{
    stack<Node *> s;
    queue<Node *> q;
    Node *cur;
    q.push(start);
    while (!q.empty())
    {
        cur = q.front();
        s.push(cur);
        q.pop();
        if (cur->rcl != NULL)
            q.push(cur->rcl);
        if (cur->lcl != NULL)
            q.push(cur->lcl);
    }
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

void Node ::searchElement(Node *start, int item)
{

    queue<Node *> q;
    q.push(start);
    Node *cur;
    int flag = 0;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur->data == item)
        {
            cout << endl
                 << "Element found!" << endl;
            flag = 1;
            return;
        }
        if (cur->lcl != NULL)
            q.push(cur->lcl);
        if (cur->rcl != NULL)
            q.push(cur->rcl);
    }
    if (flag == 0)
        cout << endl
             << "Element not found" << endl;
}

void Node::parentNode(Node *start, int ch)
{
    if (start->data == ch)
    {
        cout << endl
             << "No parent! This is the root." << endl;
        return;
    }
    queue<Node *> q;
    q.push(start);

    int flag = 0;
    Node *cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur->lcl != NULL && (cur->lcl->data) == ch)
        {
            cout << "\nThe parent is " << cur->data << endl;
            flag = 1;
            break;
        }
        else if (cur->rcl != NULL && (cur->rcl->data) == ch)
        {
            cout << "\nThe parent is " << cur->data << endl;
            flag = 1;
            break;
        }
        else
        {
            if (cur->lcl != NULL)
                q.push(cur->lcl);
            if (cur->rcl != NULL)
                q.push(cur->rcl);
        }
    }
    if (flag == 0)
        cout << "\nNode not found" << endl;
}

void Node::levelorder(Node *start)
{
    queue<Node *> q;
    q.push(start);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        if (cur->lcl != NULL)
            q.push(cur->lcl);
        if (cur->rcl != NULL)
            q.push(cur->rcl);
        cout << cur->data << " ";
    }
}

void Node::display(Node *start, int level)
{
    if (start == NULL)
        return;
    display(start->rcl, level + 1);
    for (int i = 0; i < level; i++)
        cout << "      ";
    cout << start->data << endl;
    display(start->lcl, level + 1);
}

void Node::inorder(Node *start)
{
    if (start == NULL)
        return;
    inorder(start->lcl);
    cout << start->data << " ";
    inorder(start->rcl);
}
void Node::preorder(Node *start)
{
    if (start == NULL)
        return;
    cout << start->data << " ";

    inorder(start->lcl);
    inorder(start->rcl);
}
void Node::postorder(Node *start)
{
    if (start == NULL)
        return;
    inorder(start->lcl);
    inorder(start->rcl);
    cout << start->data << " ";
}

Node *Node::createBT(Node *start, int item, string d)
{
    Node *temp = new Node();
    temp->data = item;
    temp->lcl = NULL;
    temp->rcl = NULL;
    if (start == NULL)
        return temp;
    Node *prev, *cur = start;
    int i;
    for (i = 0; i < d.length(); i++)
    {
        if (cur == NULL)
            break;
        prev = cur;
        if (d[i] == 'L')
            cur = cur->lcl;
        else
            cur = cur->rcl;
    }
    if (cur != NULL || i != d.length())
    {
        cout << endl
             << "Insertion not possible" << endl;
        delete (temp);
        return start;
    }
    if (d[i - 1] == 'L')
        prev->lcl = temp;
    else
        prev->rcl = temp;
    return start;
}

int main()
{
	
	//UNCOMMENT THE LINES BELOW TO CHECK THE FUNCTIONS
    Node *start = NULL, n;
    start = n.createBT(start, 11, "N");
    start = n.createBT(start, 192, "L");
    start = n.createBT(start, -13, "R");
    start = n.createBT(start, 4, "LL");
    start = n.createBT(start, 15, "LR");
    start = n.createBT(start, 116, "RL");
    start = n.createBT(start, 25, "RR");
    start = n.createBT(start, 900, "LLL");
    start = n.createBT(start, 9, "LLR");
    start = n.createBT(start, 10, "LRL");
    start = n.createBT(start, 11, "LRR");
    start = n.createBT(start, 12, "RLL");
    start = n.createBT(start, 13, "RLR");
    start = n.createBT(start, 14, "RRL");
    start = n.createBT(start, 15, "RRR");

    n.display(start, 0);
    // cout << endl;
    // n.inorder(start);
    // cout << endl;
    // n.postorder(start);
    // cout << endl;
    // n.preorder(start);
    // cout << endl;
    // n.levelorder(start);
    cout << endl;
    // n.parentNode(start, 7);

    // n.searchElement(start, 10);
    // n.searchElement(start, 3);

    // n.reverseLevelOrder(start);

    // n.spiralLevelOrder(start);

    // cout << "Number of leaves : " << endl;
    // cout << n.countLeaf(start) << endl;

    // cout << "Height of the tree : " << endl;
    // cout << n.heightOfTree(start, 0) << endl;

    // Node *newNode = NULL;
    // newNode = n.getMirror(start, newNode);
    // cout << "-------------------------------------------------------------------" << endl;
    // // n.display(newNode, 0);
    // cout << "-------------------------------------------------------------------" << endl;
    // // n.display(start, 0);

    // // newNode = n.createBT(newNode, 8, "LLR");
    // // cout << "-------------------------------------------------------------------" << endl;
    // n.display(newNode, 0);

    // if (n.checkMirror(start, newNode))
    //     cout << endl
    //          << "Yes! These two are mirror of each other." << endl;
    // else
    //     cout << endl
    //          << "No! They aren't mirror of each other." << endl;

    // cout << "Smallest element in the tree is: " << n.findMin(start) << endl;
    // cout << "Largest element in the tree is: " << n.findMax(start) << endl;

    // cout << "Ancestors of node : ";
    // n.ancestorsOfNode(start, 12);
    // cout << endl;
}

#include <iostream>
using namespace std;
struct trienode
{
    trienode *child[26];
    bool isWord;
};
trienode *newtrienode()
{
    trienode *temp = new trienode();
    temp->isWord = false;
    for (int i = 0; i < 26; i++)
    {
        temp->child[i] = nullptr;
    }
    return temp;
}
class trie
{
    trienode *head;

public:
    trie()
    {
        head = newtrienode();
    }
    void insert(string str)
    {
        trienode *temp = head;
        for (int i = 0; i < str.length(); i++)
        {
            if (!temp->child[str[i] - 'a'])
            {
                temp->child[str[i] - 'a'] = newtrienode();
            }
            temp = temp->child[str[i] - 'a'];
        }
        temp->isWord = true;
    }
    bool search(string str)
    {
        trienode *temp = head;
        for (int i = 0; i < str.length(); i++)
        {
            if (temp->child[str[i] - 'a'] == nullptr)
                return false;
            temp = temp->child[str[i] - 'a'];
        }
        if (temp->isWord)
        {
            return true;
        }
        return false;
    }
    bool has_child(trienode *temp)
    {
        for (int i = 0; i < 26; i++)
            if (temp->child[i])
                return true;
        return false;
    }
    bool help_erase(trienode *temp, string str)
    {
        if (str.length() == 1)
        {
            if (has_child(temp))
            {
                temp->isWord = false;
                return false;
            }
            else
            {
                delete (temp);
                return true;
            }
        }
        if (help_erase(temp->child[str[0] - 'a'], str.substr(1)))
        {
            if (!temp->isWord)
            {
                temp->child[str[0] - 'a'] = nullptr;
                return true;
            }
            else
            {
                temp->child[str[0] = 'a'] = nullptr;
                return false;
            }
        }
        return false;
    }
    void erase(string str)
    {
        trienode *temp = head;
        if (help_erase(temp, str))
        {
            temp->child[str[0]] = nullptr;
        }
        return;
    }
};

int main()
{
    int choice;
    string str;
    trie obj;
    bool flag = true;
    while (flag)
    {
        cout << "\nMenu:\n1. Insert\n2. search\n3. Delete\n4. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> str;
            obj.insert(str);
            cout << endl;
            break;
        case 2:
            cin >> str;
            cout << (obj.search(str) ? "Found\n" : "Not Found\n");
            break;
        case 3:
            cin >> str;
            if (obj.search(str))
            {
                obj.erase(str);
                cout << "Word deleted\n";
            }
            else
            {
                cout << "Word does not exist";
            }
            break;
        default:
            flag = false;
            break;
        }
    }
    return 0;
}
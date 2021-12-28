#include <iostream>
#include <list>
template <typename _Ty, typename _Dy>
class Collection {

private:
    using _My_Pair = std::pair<_Ty, _Dy>;
    using const_ref_My_Pair = const std::pair<_Ty, _Dy>&;
    
    struct Node
    {
        friend class Iterator;
        Node(_My_Pair& _Pr, Node* l = nullptr, Node* r = nullptr) :_pair(_Pr), left((l)), right((r)){};
        Node* left, * right;
        _My_Pair _pair;
        ~Node() { std::cout << "~Node\n"; }
    };
    Node* root;
    void recursion(_My_Pair& pair_,  Node*& treeNode);
    int s = 0;
    void del_recursion(Node*& treeNode);
    void treeWalk(Node* root,std::list<Node*>&);
    Node* deleting(Node*& root, _Ty& key) {
        if (!root)
            return nullptr;
        if (key < root->_pair.first) {
            root->left = deleting(root->left, key);
        }
        else if (key > root->_pair.first) {
            root->right = deleting(root->right, key);
        }
        else if (root->left && root->right) {
            Node* ptr = root;
            ptr = ptr->left;
            while (ptr->right)
                ptr = ptr->right;
            root->_pair = ptr->_pair;
            root->right = deleting(root->right, root->_pair.first);
        }
        else {
            if (root->left)
                root = root->left;
            else if (root->right)
                root = root->right;
            else root = nullptr;
        }
        return root;
    }
    Node* CopyTree(Node* node)
    {
        if (node == NULL)
            return NULL;

        Node* newnode = new Node(node->_pair);
        newnode->left = CopyTree(node->left);
        newnode->right = CopyTree(node->right);

        return newnode;
    }
public:
    class Iterator {
    public:
        Iterator(Node* n = nullptr) :node(n) { };
        Iterator(const Iterator& orig) :node(orig.node){}
        Iterator(Node* n,std::list<Node*>& list) :node(n), nodeList(list) {}
        ~Iterator() { if (node)delete node; }

        Iterator& operator++();
        Iterator operator++(int);

        bool operator!=(Iterator const& it);
        _My_Pair operator*();
        bool operator==(const Iterator & it) { return node == it.node; }
    private:
        Node* node;
        std::list<Node*> nodeList;
    };
    Collection() :root(nullptr) {};
    Collection(const Collection&);
    Collection(Collection&&);
    ~Collection() { clear(); }

    Collection& operator=(const Collection&);
    Collection operator=( Collection&&);
    bool operator==( Collection&);

    _Dy& operator[](_Ty&);

    _My_Pair& at(_Ty);

    void insert(_My_Pair _My);
    void insert(_Ty&, _Dy&);

    void erase(_Ty&);
    void erase(int);

    int size() { return s; }
    
    bool empty();

    Iterator begin();
    Iterator end();

    bool is_enable(_Ty&);
    void clear();
};

template <typename _Ty, typename _Dy>
void Collection<_Ty, _Dy>::erase(_Ty& key)
{
    if (s > 0) {
        root = deleting(root, key);
        s--;
    }
    else throw std::invalid_argument("try to delete clear container");
}
template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy>& Collection<_Ty, _Dy>::operator=(const Collection<_Ty, _Dy>& col)
{
    if (root)
        clear();
    root = CopyTree(col.root);
    s = col.s;
    return *this;
}

template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy>::Collection<_Ty, _Dy>(const Collection& col)
{
    root = CopyTree(col.root);
    s = col.s;
}

template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy> Collection<_Ty, _Dy>::operator=(Collection<_Ty, _Dy>&& col) {
    if(root)
       clear();
    s = 0;
    root = (col.root);
    col.root = nullptr;
    s = col.size();
    col.s = 0;
}
template <typename _Ty, typename _Dy>
bool Collection<_Ty, _Dy>::operator==( Collection<_Ty, _Dy>& col)
{
    if (col.size() == s) {
        Collection<_Ty, _Dy>::Iterator it1 = begin();
        Collection<_Ty, _Dy>::Iterator it2 = col.begin();
        for (; it1 != end(), it2 != col.end(); ++it1, ++it2) {
            if (((*it1).first != (*it2).first) || ((*it1).second != (*it2).second))
                return false;
        }
        return true;
    }
    else return false;
}

template <typename _Ty, typename _Dy>
void Collection<_Ty, _Dy>::insert(_Ty&_ty, _Dy&_dy)
{
    _My_Pair _my_pair = std::make_pair(_ty, _dy);
    insert(_my_pair);
}

template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy>::Iterator  Collection<_Ty, _Dy>::Iterator::operator++(int) {
    Collection<_Ty, _Dy>::Iterator tmp(*this); operator++(); return tmp;
}

template <typename _Ty, typename _Dy>
void  Collection<_Ty, _Dy>::treeWalk(Node* root, std::list<Node*>& list)
{
    if (root) {
        list.push_back(root);
        treeWalk(root->left,list);
        treeWalk(root->right, list);
    }
}

template <typename _Ty, typename _Dy>
 Collection<_Ty, _Dy>::_My_Pair&  Collection<_Ty, _Dy>::at(_Ty __ty)
{
     for (auto& c : *this) {
         if (__ty == c.second)
             return c;
     }

     throw std::out_of_range("key not found\n");
}

template <typename _Ty, typename _Dy>
bool Collection<_Ty, _Dy>::is_enable(_Ty& _type)
{
    for (auto c : *this) {
        if (c.first == _type)
            return true;
    }
    return false;
}

template <typename _Ty, typename _Dy>
_Dy& Collection<_Ty, _Dy>::operator[](_Ty& _type)
{
    for (auto c : *this) {
        if (c.first == _type)
        {
            return c.second;
        }
    }
    throw std::exception("key finding error\n");
}


template <typename _Ty, typename _Dy>
void Collection<_Ty, _Dy>::erase(int pos)
{
    Collection<_Ty, _Dy>::Iterator it = begin();
    for (int i = 0; it != end(); ++it,i++)
    {
        if (i == pos) {
            

        }
    }
}


template <typename _Ty, typename _Dy>
void Collection<_Ty, _Dy>::del_recursion(Collection<_Ty, _Dy>::Node*& treeNode) {
    if(treeNode->left) del_recursion(treeNode->left);
    if(treeNode->right) del_recursion(treeNode->right);
    delete treeNode;
}


template <typename _Ty, typename _Dy>
void Collection<_Ty, _Dy>::clear() {
    if (!root)
        throw std::logic_error("erasing empy container\n");
    del_recursion(root);
    s = 0;
}

template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy>::_My_Pair Collection<_Ty, _Dy>::Iterator::operator*()
{
    if (!node)
        throw std::invalid_argument("dereference of empty iterator\n");
    return (node->_pair);
}
/** 
    \brief Constructor(&&)
     Gets an rvalue reference type object
*/
template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy>::Collection(Collection<_Ty, _Dy>&& _new) {
    clear(); root = std::move(_new.root);
}

/**
    \brief Checking complitness of container
*/
template <typename _Ty, typename _Dy>
bool Collection<_Ty, _Dy>::empty() 
{
    if (s < 0) return true;
    else return false;
}


template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy>::Iterator& Collection<_Ty, _Dy>::Iterator:: operator++()
{

    if (nodeList.empty())
        node = nullptr;
    else {
        node = nodeList.front();
        nodeList.pop_front();
    }
    return *this;
}

//template <typename _Ty, typename _Dy>
//Collection<_Ty, _Dy>::_My_Pair Collection<_Ty, _Dy>::operator[](int pos) {
//    if (!root)
//        throw std::invalid_argument("container is already clear\n");
//    if (pos > s||pos<0)
//        throw std::invalid_argument("argument more than container size\n");
//    Collection<_Ty, _Dy>::Iterator it = begin();
//    int i = 0;
//    for (auto c : *this) 
//    {
//        if (i++ == pos) return c;
//    }
//}

template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy>::Iterator Collection<_Ty, _Dy>::begin() {
    if (!root)
        throw std::logic_error("error to dereference iterator");
    std::list<Node*>list;
    treeWalk(root, list);
    Node* ptr = *list.begin();
    list.pop_front();
    return Iterator(ptr,list);
}

template <typename _Ty, typename _Dy>
void Collection<_Ty, _Dy>::recursion(_My_Pair& pair_,  Node*& treeNode) {

    if (!treeNode) 
    {
        treeNode = new Node(pair_, nullptr, nullptr);
        return;
    }
    else 
    {
        if (treeNode->_pair.first > pair_.first)
        {
            recursion(pair_,  treeNode->left);
        }
        else recursion(pair_,  treeNode->right);
    }
}


template <typename _Ty, typename _Dy>
void Collection<_Ty, _Dy>::insert(Collection<_Ty, _Dy>::_My_Pair _My)
{
    recursion(_My,  root);
    s++;
}

template <typename _Ty, typename _Dy>
Collection<_Ty, _Dy>::Iterator Collection<_Ty, _Dy>::end()
{
    return Collection<_Ty, _Dy>::Iterator(nullptr);
}

/*Tree on pointers*/

template <typename _Ty, typename _Dy>
bool Collection<_Ty, _Dy>::Iterator::operator!=(Collection<_Ty, _Dy>::Iterator const& it) {
    return /*true;*/(node!= it.node);
}
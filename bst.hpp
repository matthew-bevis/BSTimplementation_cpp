
template <typename T>
BST<T>::BST(int th)
{
    th = 1;
    int numNode = 0;
    vector<T> tree(0);
}

template <typename T>
BST<T>::BST(const string input, int th)
{
    vector<T> v(0);
    int numNode = 0;
    istringstream iss;
    T data;
    iss.str(input);
    while(iss >> data)
        v.push_back(data);
    for(int i=0; i < v.size(); i++)
        insert(v[i]);
}

template <typename T>
BST<T>::BST(const BST &rhs)
{
    root = clone(rhs.root);
}

template <typename T>
BST<T>::BST(BST &&rhs)
{
    root = clone(rhs.root);
    makeEmpty();
}

template <typename T>
BST<T>::~BST()
{
    makeEmpty();
}

template <typename T>
void BST<T>::buildFromInputString(const string input)
{
    vector<T> v(0);
    int numNode = 0;
    istringstream iss;
    T data;
    iss.str(input);
    while(iss >> data)
        v.push_back(data);
    for(int i=0; i < v.size(); i++)
        insert(v[i]);
}

template <typename T>
const BST<T>& BST<T>::operator=(const BST &rhs)
{
    root = clone(rhs.root);
}

template <typename T>
const BST<T>& BST<T>::operator=(BST &&rhs)
{
    root = clone(rhs.root);
    makeEmpty();
}

template <typename T>
bool BST<T>::empty()
{
    if(numOfNodes(root) == 0)
        return true;
    else
        return false;
}

template <typename T>
void BST<T>::printInOrder() const
{
    ostream &os = cout;
    printInOrder(root, os);
}

template <typename T>
void BST<T>::printLevelOrder() const
{
    ostream &os = cout;
    printLevelOrder(root, os);
}

template <typename T>
int BST<T>::numOfNodes() const
{
    return numOfNodes(root);
}

template <typename T>
int BST<T>::height() const
{
    return height(root);
}

template <typename T>
void BST<T>::makeEmpty()
{
    makeEmpty(root);
}

template <typename T>
void BST<T>::insert(const T& v)
{
    return insert(v, root);
}

template <typename T>
void BST<T>::insert(T &&v)
{
    insert(v, root);
}

template <typename T>
void BST<T>::remove(const T& v)
{
    remove(v, root);
}

template <typename T>
bool BST<T>::contains(const T& v)
{
    return contains(v, root);
}

template <typename T>
const T& BST<T>::findMin() const
{
    return findMin(root);
}

template <typename T>
const T& BST<T>::findMax() const
{
    return findMax(root);
}

template <typename T>
void BST<T>::printInOrder(BSTNode *t, ostream& os) const
{
    if(t!=nullptr)
    {
        printInOrder(t->left, os);
        os << t->element << endl;
        printInOrder(t->right, os);
    }
}

template <typename T>
void BST<T>::printLevelOrder(BSTNode *t, ostream& os) const
{

}

template <typename T>
void BST<T>::makeEmpty(BSTNode *&t)
{
    if(t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename T>
void BST<T>::insert(const T& v, BSTNode *&t)
{
    if(t==nullptr)
    {
        t = new BSTNode{v, nullptr, nullptr};
    }

    else if(v < t->element)
    {
        insert(v,t->left);
    }

    else if( v > t->element)
    {
        insert(v, t->right);
    }

    else;
}

template <typename T>
void BST<T>::insert(T&& v, BSTNode* &t)
{
    if(t==nullptr)
    {
        t = new BSTNode{v, nullptr, nullptr};
    }
    else if(v < t->element)
    {
        insert(v,t->left);
    }
    else if( v > t->element)
    {
        insert(v, t->right);
    }
    else;
}

template <typename T>
void BST<T>::remove(const T& v, BSTNode *&t)
{
    if(t==nullptr)
        return;
    if(v < t->element)
        remove(v,t->left);
    else if(v > t->element)
        remove(v,t->right);
    else if(t->left != nullptr && t->right != nullptr)
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else
    {
        BSTNode* oldNode = t;
        t = (t->left != nullptr) ? t->left:t->right;
        delete oldNode;
    }
}
template <typename T>
bool BST<T>::contains(const T& v, BSTNode *&t)//may need other params
{
    if(t==nullptr)
        return false;
    else if(v < t->element)
        return contains(v, t->left);
    else if(v > t->element)
        return contains(v, t->right);
    else
        return true;
}

template <typename T>
typename BST<T>::BSTNode* BST<T>::findMin(BSTNode *t) const
{
    if(t==nullptr)
        return nullptr;
    if(t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename T>
typename BST<T>::BSTNode* BST<T>::findMax(BSTNode *t) const
{
    if(t==nullptr)
        return nullptr;
    if(t->right == nullptr)
        return t;
    return findMin(t->right);
}

template <typename T>
int BST<T>::numOfNodes(BSTNode *t) const
{
    if (t!=nullptr)
    {
        return numOfNodes(t->left);
    }
}

template <typename T>
int BST<T>::height(BSTNode *t) const
{

}

template <typename T>
typename BST<T>::BSTNode* BST<T>::clone(BSTNode *t) const
{
    if(t == nullptr)
        return nullptr;
    else
        return new BSTNode{t->element, clone(t->left),clone(t->right)};
}

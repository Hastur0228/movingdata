#ifndef INC_9_BINARYSEARCHTREE_H
#define INC_9_BINARYSEARCHTREE_H

#include <iostream> 

template<class KEY, class OTHER>
struct SET
{
    KEY key;
    OTHER other;
};

template<class KEY, class OTHER>
class binarySearchTree {
private:
    struct BinaryNode
    {
        SET<KEY, OTHER> data;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode(const SET<KEY, OTHER>& thedata, BinaryNode* lt = 0, BinaryNode* rt = 0)
            :data(thedata), left(lt), right(rt) {}
    };
    BinaryNode* root;

public:
    // ���캯��
    binarySearchTree();
    // ��������
    ~binarySearchTree();
    // ���÷ǵݹ�ķ�ʽʵ�ֲ��Һ���
    SET<KEY, OTHER>* find(const KEY& x) const;
    // ���÷ǵݹ�ķ�ʽʵ�ֲ��뺯��
    void insert(const SET<KEY, OTHER>& x);
    // ���÷ǵݹ�ķ�ʽʵ��ɾ������
    void remove(const KEY& x);

    // �������Ҫ��ӵ��������������ڴ˴�������ʵ�֡�
    void makeEmpty(BinaryNode* t);
};

template<class KEY, class OTHER>
binarySearchTree<KEY, OTHER>::binarySearchTree() {
    // �ڴ�ʵ�ֹ��캯��
    root = 0;
}

template<class KEY, class OTHER>
binarySearchTree<KEY, OTHER>::~binarySearchTree() {
    // �ڴ�ʵ����������
    makeEmpty(root);
}

template<class KEY, class OTHER>
void binarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode* t)
{
    if (t == 0) return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

template<class KEY, class OTHER>
SET<KEY, OTHER>* binarySearchTree<KEY, OTHER>::find(const KEY& x)const
{
    BinaryNode* t = root;
    while (t != 0 && t->data.key != x)
    {
        if (x > t->data.key) t = t->right;
        else t = t->left;
    }
    if (t == 0) return 0;
    else return (SET<KEY, OTHER> *)t;
}

template<class KEY, class OTHER>
void binarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x)
{
    BinaryNode* nd = new BinaryNode(x, 0, 0);
    if (root == 0) { root = nd; return; }
    BinaryNode* now = root;
    while (true)
    {
        if (x.key > now->data.key)
        {
            if (now->right == 0)
            {
                now->right = nd;
                break;
            }
            now = now->right;
        }
        else if (now->left == 0)
        {
            now->left = nd;
            break;
        }
        else now = now->left;
    }
}

template<class KEY, class OTHER>
void binarySearchTree<KEY, OTHER>::remove(const KEY& x)
{
    BinaryNode* now = root;
    BinaryNode* parent = 0;
    int leftOrRight;
    while (now != 0)
    {
        if (x > now->data.key)
        {
            leftOrRight = 2;
            parent = now;
            now = now->right;
        }
        else if (x < now->data.key)
        {
            leftOrRight = 1;
            parent = now;
            now = now->left;
        }
        else break;
    }
    if (now == 0)
        return;
    if (now->left != 0 && now->right != 0)
    {
        BinaryNode* tmp = now->right;
        if (tmp->left == 0)
        {
            now->data.key = tmp->data.key;
            now->right = tmp->right;
            delete tmp;
            return;
        }
        while (tmp->left->left != 0) tmp = tmp->left;
        BinaryNode* deleted = tmp->left;
        now->data.key = deleted->data.key;
        tmp->left = deleted->right;
        delete deleted;
        return;
    }
    if (now == root)
    {
        if (root->left == 0) root = root->right; else root = root->left;
        delete now;
        return;
    }
    if (leftOrRight == 1)
        parent->left = (now->left == 0 ? now->right : now->left);
    else parent->right = (now->left == 0 ? now->right : now->left);
    delete now;
    return;
}
#endif //INC_9_BINARYSEARCHTREE_H

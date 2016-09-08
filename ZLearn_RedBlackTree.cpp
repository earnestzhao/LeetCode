#include <queue>
#include <iomanip>
#include <iostream>


// 红黑树节点颜色
enum RBTreeNodeColor
{
    BLACK,
    RED,
};


// 红黑树节点结构
struct RBTreeNode
{
    // 构造方法
    RBTreeNode(int iValue) : value(iValue), color(BLACK), left(NULL), right(NULL), parent(NULL)
    {
        
    }
    
    // 数据域
    int value;
    
    // 节点颜色
    RBTreeNodeColor color;
    
    // 指向左子节点指针
    RBTreeNode * left;
    
    // 指向右子节点指针
    RBTreeNode * right;
    
    // 指向父节点指针
    RBTreeNode * parent;
};


// 左旋操作
RBTreeNode * LeftRotate(RBTreeNode * pstRotateUpLevelNode)
{
    // 当前指针为空，无法左旋
    if (pstRotateUpLevelNode == NULL)
    {
        return NULL;
    }
    
    // 没有右孩子，无法左旋
    if (pstRotateUpLevelNode -> right == NULL)
    {
        return pstRotateUpLevelNode;
    }
    
    // 旋转后新的上层节点
    RBTreeNode * pstNewUpLevelNode = pstRotateUpLevelNode -> right;
    
    // 当前上层节点的父节点
    RBTreeNode * pstUpLevelNodeParent = pstRotateUpLevelNode -> parent;
    
    // 判断当前节点是否是根节点 ...
    if (pstUpLevelNodeParent != NULL)
    {
        // 非根节点，令父节点对应的指针域，指向旋转后新的上层节点
        if (pstUpLevelNodeParent -> left == pstRotateUpLevelNode)
        {
            pstUpLevelNodeParent -> left = pstNewUpLevelNode;
        }
        else
        {
            pstUpLevelNodeParent -> right = pstNewUpLevelNode;
        }
    }
    
    // 当前上层节点的右指针，指向旋转后新的上层节点的左孩子
    pstRotateUpLevelNode -> right = pstNewUpLevelNode -> left;
    
    // 设置上一步关系转换的父指针
    if (pstNewUpLevelNode -> left != NULL)
    {
        pstNewUpLevelNode -> left -> parent = pstRotateUpLevelNode;
    }
    
    // 旋转后新的上层节点的左指针，指向当前上层节点
    pstNewUpLevelNode -> left = pstRotateUpLevelNode;
    
    // 设置上一步关系转换的父指针
    pstRotateUpLevelNode -> parent = pstNewUpLevelNode;
    
    // 返回新的上层节点
    return pstNewUpLevelNode;
}


// 右旋操作
RBTreeNode * RightRotate(RBTreeNode * pstRotateUpLevelNode)
{
    // 当前指针为空，无法右旋
    if (pstRotateUpLevelNode == NULL)
    {
        return NULL;
    }
    
    // 没有左孩子，无法右旋
    if (pstRotateUpLevelNode -> left == NULL)
    {
        return pstRotateUpLevelNode;
    }
    
    // 旋转后新的上层节点
    RBTreeNode * pstNewUpLevelNode = pstRotateUpLevelNode -> left;
    
    // 当前上层节点的父节点
    RBTreeNode * pstUpLevelNodeParent = pstRotateUpLevelNode -> parent;
    
    // 判断当前节点是否是根节点 ...
    if (pstUpLevelNodeParent != NULL)
    {
        // 非根节点，令父节点对应的指针域，指向旋转后新的上层节点
        if (pstUpLevelNodeParent -> left == pstRotateUpLevelNode)
        {
            pstUpLevelNodeParent -> left = pstNewUpLevelNode;
        }
        else
        {
            pstUpLevelNodeParent -> right = pstNewUpLevelNode;
        }
    }
    
    // 当前上层节点的左指针，指向旋转后新的上层节点的右孩子
    pstRotateUpLevelNode -> left = pstNewUpLevelNode -> right;
    
    // 设置上一步关系转换的父指针
    if (pstNewUpLevelNode -> right != NULL)
    {
        pstNewUpLevelNode -> right -> parent = pstRotateUpLevelNode;
    }
    
    // 旋转后新的上层节点的右指针，指向当前上层节点
    pstNewUpLevelNode -> right = pstRotateUpLevelNode;
    
    // 设置上一步关系转换的父指针
    pstRotateUpLevelNode -> parent = pstNewUpLevelNode;
    
    // 返回新的上层节点
    return pstNewUpLevelNode;
}


// 插入
RBTreeNode * Insert(RBTreeNode * pstRoot, int iValue)
{
    // 生成新节点
    RBTreeNode * pstNewNode = new RBTreeNode(iValue);
    
    // 根节点为空直接返回
    if (pstRoot == NULL)
    {
        return pstNewNode;
    }
    
    // 将新节点着为红色
    pstNewNode -> color = RED;
    
    // 标记：插入到目标节点的左边
    bool bInsertOnLeft = true;
    
    // 新节点待插入的父节点位置
    RBTreeNode * pstInsertParent = NULL;
    
    // 寻找新节点待插入的父节点位置
    for (RBTreeNode * pstCurrent = pstRoot; pstCurrent != NULL;)
    {
        if (iValue <= pstCurrent -> value)
        {
            if (pstCurrent -> left == NULL)
            {
                bInsertOnLeft   = true;
                pstInsertParent = pstCurrent;
            }
            
            pstCurrent = pstCurrent -> left;
        }
        else
        {
            if (pstCurrent -> right == NULL)
            {
                bInsertOnLeft   = false;
                pstInsertParent = pstCurrent;
            }
            
            pstCurrent = pstCurrent -> right;
        }
    }
    
    // 插入新节点
    if (bInsertOnLeft)
    {
        pstInsertParent -> left = pstNewNode;
    }
    else
    {
        pstInsertParent -> right = pstNewNode;
    }
    
    // 设置新节点的父节点
    pstNewNode -> parent = pstInsertParent;
    
    // 维持红黑树性质的调整 ...
    for (RBTreeNode * pstCurrent = pstNewNode; pstCurrent != NULL         && pstCurrent -> parent != NULL
                                            && pstCurrent -> color == RED && pstCurrent -> parent -> color == RED;)
    {
        // 父节点，祖父节点，和叔叔节点
        RBTreeNode * pstParentNode = pstCurrent    -> parent;
        RBTreeNode * pstGrandNode  = pstParentNode -> parent;
        RBTreeNode * pstUncleNode  = NULL;
        
        // 根据指针关系计算出叔叔节点
        if (pstParentNode == pstGrandNode -> left)
        {
            pstUncleNode = pstGrandNode -> right;
        }
        else
        {
            pstUncleNode = pstGrandNode -> left;
        }
        
        // 叔叔节点为红色，则 Case 1 ...
        if (pstUncleNode != NULL && pstUncleNode -> color == RED)
        {
            pstGrandNode  -> color = RED;
            pstUncleNode  -> color = BLACK;
            pstParentNode -> color = BLACK;
            pstCurrent             = pstGrandNode;
        }
        else
        {
            // 两种 Zigzag 形状，分别做左右旋转处理 ...
            if (pstParentNode == pstGrandNode -> left)
            {
                // Case 2：Zigzag 情况调整成 Zigzig 形状
                if (pstCurrent == pstParentNode -> right)
                {
                    pstCurrent = LeftRotate(pstParentNode);
                }
                
                // Case 3：处理 Zigzig 情况旋转
                pstCurrent = RightRotate(pstGrandNode);
            }
            else if (pstParentNode == pstGrandNode -> right)
            {
                // Case 2：Zigzag 情况调整成 Zigzig 形状
                if (pstCurrent == pstParentNode -> left)
                {
                    pstCurrent = RightRotate(pstParentNode);
                }
                
                // Case 3：处理 Zigzig 情况旋转
                pstCurrent = LeftRotate(pstGrandNode);
            }
            else
            {
                break;
            }
            
            // Case 3：Zigzig 需要换色
            pstGrandNode -> color = RED;
            pstCurrent   -> color = BLACK;
            
            // 新的根节点
            if (pstCurrent -> parent == NULL)
            {
                pstRoot = pstCurrent;
            }
        }
    }
    
    // Case 1 之后立即跳出循环的情况，根节点可能被设置成红色，这里恢复成黑色
    pstRoot -> color = BLACK;
    
    // 返回根节点
    return pstRoot;
}


// 测试层次遍历
void LevelTraversal(RBTreeNode * pstRoot)
{
    std::queue<RBTreeNode *> queueTraversal;
    queueTraversal.push(pstRoot);
    
    while (!queueTraversal.empty())
    {
        RBTreeNode * pstCurrent = queueTraversal.front();
        queueTraversal.pop();
        
        if (pstCurrent != NULL)
        {
            std::cout << "(" << pstCurrent -> value << "," << (pstCurrent -> color ? "RED" : "BLACK") << "),";
            queueTraversal.push(pstCurrent -> left);
            queueTraversal.push(pstCurrent -> right);
        }
        else
        {
            std::cout << "(NIL,BLACK),";
        }
    }
    
    std::cout << "END" << std::endl;
}


// 测试
int main()
{
    // 输入数据
    int iTestValue = 0;
    
    // 待测试红黑树
    RBTreeNode * pstRoot = NULL;
    
    // 输出插入提示
    std::cout << "Input Insert Elements: ";
    
    // 输入元素列表，以0结束
    while (std::cin >> iTestValue)
    {
        if (iTestValue == 0)
        {
            break;
        }
        
        pstRoot = Insert(pstRoot, iTestValue);
    }
    
    // 插入后看结果
    LevelTraversal(pstRoot);
    
    // 退出
    return 0;
}


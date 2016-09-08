#include <vector>
#include <cstdlib>

#include <iomanip>
#include <iostream>



// 跳表节点类型
enum SkipListNodeType
{
    SLNT_NORMAL_VALUE,
    SLNT_INFINITY_SMALL,
    SLNT_INFINITY_LARGE,
};

// 跳表节点
struct SkipListNode
{
    // 构造方法
    SkipListNode(int iValue, SkipListNodeType iType) : value(iValue), type(iType), left(NULL), right(NULL), up(NULL), down(NULL)
    {
        
    }
    
    // 数据
    int value;
    
    // 类型
    SkipListNodeType type;
    
    // 左指针
    SkipListNode * left;
    
    // 右指针
    SkipListNode * right;
    
    // 上指针
    SkipListNode * up;
    
    // 下指针
    SkipListNode * down;
};



// 跳表层次最大值
const int SKIP_LIST_MAX_LEVEL = 64; 

// 跳表
struct SkipList
{
    SkipList() : currentHighestLevel(0)
    {
        for (int iIndex = 0; iIndex < SKIP_LIST_MAX_LEVEL; iIndex ++)
        {
            levelHeadList[iIndex] = new SkipListNode(0, SLNT_INFINITY_SMALL);
            levelTailList[iIndex] = new SkipListNode(0, SLNT_INFINITY_LARGE);
            
            levelTailList[iIndex] -> left  = levelHeadList[iIndex];
            levelHeadList[iIndex] -> right = levelTailList[iIndex];
            
            if (iIndex > 0)
            {
                levelHeadList[iIndex] -> down = levelHeadList[iIndex - 1];
                levelTailList[iIndex] -> down = levelTailList[iIndex - 1];
                
                levelHeadList[iIndex - 1] -> up = levelHeadList[iIndex];
                levelTailList[iIndex - 1] -> up = levelTailList[iIndex];
            }
        }
        
        randomSeed = static_cast<unsigned>(time(NULL));
    }
    
    // 每层头节点列表
    SkipListNode * levelHeadList[SKIP_LIST_MAX_LEVEL];
    
    // 每层尾节点列表
    SkipListNode * levelTailList[SKIP_LIST_MAX_LEVEL];
    
    // 当前最高层数
    int currentHighestLevel;
    
    // 随机数种子
    unsigned int randomSeed;
};



// 跳表中和 iValue 相等的节点，或刚好小于 iValue 的节点的搜索路径
void JustLessOrEqualSearchPath(SkipList * pstSkipList, int iValue, std::vector<SkipListNode *> & vecNodePath)
{
    // 取最高层索引
    int iLevelIndex = pstSkipList -> currentHighestLevel;
    
    // 执行查找循环 ...
    for (SkipListNode * pstCurrent = pstSkipList -> levelHeadList[iLevelIndex]; pstCurrent != NULL;)
    {
        // 向右找到大于等于待查找值的节点 ...
        if (pstCurrent -> type == SLNT_INFINITY_SMALL || (pstCurrent -> type == SLNT_NORMAL_VALUE && pstCurrent -> value < iValue))
        {
            pstCurrent = pstCurrent -> right;
        }
        else
        {
            // 退到刚好比待查值小的节点
            if (pstCurrent -> type == SLNT_INFINITY_LARGE || (pstCurrent -> type == SLNT_NORMAL_VALUE && pstCurrent -> value > iValue))
            {
                pstCurrent = pstCurrent -> left;
            }
            
            // 将节点加入路径中
            vecNodePath.push_back(pstCurrent);
            
            // 探查下一层
            pstCurrent = pstCurrent -> down;
        }
    }
}


// 插入
void Insert(SkipList * pstSkipList, int iValue)
{
    // 搜索路径
    std::vector<SkipListNode *> vecNodePath;
    
    // 获取当前值相关搜索路径
    JustLessOrEqualSearchPath(pstSkipList, iValue, vecNodePath);
    
    // 记录下层节点
    SkipListNode * pstDownNewNode = NULL;
    
    // 执行插入
    for (int iIndex = static_cast<int>(vecNodePath.size() - 1); true; iIndex --)
    {
        // 创建新节点，定义左右节点变量
        SkipListNode * pstNewNode   = new SkipListNode(iValue, SLNT_NORMAL_VALUE);
        SkipListNode * pstLeftNode  = NULL;
        SkipListNode * pstRightNode = NULL;
        
        // 取左右节点
        if (iIndex >= 0)
        {
            pstLeftNode  = vecNodePath[iIndex];
            pstRightNode = pstLeftNode -> right;
        }
        else
        {
            if (pstSkipList -> currentHighestLevel >= SKIP_LIST_MAX_LEVEL)
            {
                break;
            }
            
            pstSkipList -> currentHighestLevel ++;
            pstLeftNode  = pstSkipList -> levelHeadList[pstSkipList -> currentHighestLevel];
            pstRightNode = pstSkipList -> levelTailList[pstSkipList -> currentHighestLevel];
        }
        
        // 将新节点加入当前层次链表
        pstLeftNode  -> right = pstNewNode;
        pstRightNode -> left  = pstNewNode;
        
        // 将新节点加入当前层次链表
        pstNewNode -> left  = pstLeftNode;
        pstNewNode -> right = pstRightNode;
        
        // 新节点做上下层连接
        if (pstDownNewNode != NULL)
        {
            pstDownNewNode -> up   = pstNewNode;
            pstNewNode     -> down = pstDownNewNode;
        }
        
        // 硬币随机，未选中提升或超过最大层数则退出循环
        if (rand_r(&pstSkipList -> randomSeed) % 2)
        {
            break;
        }
        
        // 更新下层节点记录
        pstDownNewNode = pstNewNode;
    }
}


// 删除
bool Delete(SkipList * pstSkipList, int iValue)
{
    // 搜索路径
    std::vector<SkipListNode *> vecNodePath;
    
    // 获取当前值相关搜索路径
    JustLessOrEqualSearchPath(pstSkipList, iValue, vecNodePath);
    
    // 搜索路径中最后一个节点
    int iPathEndIndex = static_cast<int>(vecNodePath.size() - 1);
    
    // 待删除节点不存在返回
    if (vecNodePath[iPathEndIndex] -> type != SLNT_NORMAL_VALUE || vecNodePath[iPathEndIndex] -> value != iValue)
    {
        return false;
    }
    
    // 执行删除
    for (int iIndex = iPathEndIndex; iIndex >= 0 && vecNodePath[iIndex] -> type == SLNT_NORMAL_VALUE && vecNodePath[iIndex] -> value == iValue; iIndex --)
    {
        // 取目标节点和左右节点
        SkipListNode * pstDstNode   = vecNodePath[iIndex];
        SkipListNode * pstLeftNode  = pstDstNode -> left;
        SkipListNode * pstRightNode = pstDstNode -> right;
        
        // 链表中摘除目标节点
        pstLeftNode  -> right = pstRightNode;
        pstRightNode -> left  = pstLeftNode;
        
        // 回收内存
        delete pstDstNode;
        pstDstNode = NULL;
    }
    
    // 删除成功
    return true;
}


// 检测存在
bool Exist(SkipList * pstSkipList, int iValue)
{
    // 搜索路径
    std::vector<SkipListNode *> vecNodePath;
    
    // 获取当前值相关搜索路径
    JustLessOrEqualSearchPath(pstSkipList, iValue, vecNodePath);
    
    // 取路径中最后一个节点
    SkipListNode * pstDstNode = vecNodePath[vecNodePath.size() - 1];
    
    // 判断并返回结果
    return pstDstNode -> type == SLNT_NORMAL_VALUE && pstDstNode -> value == iValue;
}



// 测试遍历方法
void Traversal(SkipList * pstSkipList)
{
    for (int iLevelIndex = pstSkipList -> currentHighestLevel; iLevelIndex >= 0; iLevelIndex --)
    {
        std::cout << "Level " << iLevelIndex << " --->>   ";
        
        for (SkipListNode * pstCurrent = pstSkipList -> levelHeadList[iLevelIndex]; pstCurrent != NULL; pstCurrent = pstCurrent -> right)
        {
            if (pstCurrent -> type == SLNT_NORMAL_VALUE)
            {
                std::cout << pstCurrent -> value << " -> ";
            }
        }
        
        std::cout << "END" << std::endl;
    }
}


// 测试
int main()
{
    // 输入值
    int iTestValue = 0;
    
    // 待测试的跳表
    SkipList stSkipList;
    
    // 输出插入提示
    std::cout << "Input Insert Elements: ";
    
    // 输入元素列表，以0结束
    while (std::cin >> iTestValue)
    {
        if (iTestValue == 0)
        {
            break;
        }
        
        Insert(&stSkipList, iTestValue);
    }
    
    // 插入后看结果
    Traversal(&stSkipList);
    
    // 输出删除提示
    std::cout << "Input Delete Elements: ";
    
    // 删除元素
    while (std::cin >> iTestValue)
    {
        if (iTestValue == 0)
        {
            break;
        }
        
        Delete(&stSkipList, iTestValue);
    }
    
    // 删除后看结果
    Traversal(&stSkipList);
    
    // 退出
    return 0;
}


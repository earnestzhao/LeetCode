#include <vector>
#include <cstdlib>

#include <iomanip>
#include <iostream>



// ����ڵ�����
enum SkipListNodeType
{
    SLNT_NORMAL_VALUE,
    SLNT_INFINITY_SMALL,
    SLNT_INFINITY_LARGE,
};

// ����ڵ�
struct SkipListNode
{
    // ���췽��
    SkipListNode(int iValue, SkipListNodeType iType) : value(iValue), type(iType), left(NULL), right(NULL), up(NULL), down(NULL)
    {
        
    }
    
    // ����
    int value;
    
    // ����
    SkipListNodeType type;
    
    // ��ָ��
    SkipListNode * left;
    
    // ��ָ��
    SkipListNode * right;
    
    // ��ָ��
    SkipListNode * up;
    
    // ��ָ��
    SkipListNode * down;
};



// ���������ֵ
const int SKIP_LIST_MAX_LEVEL = 64; 

// ����
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
    
    // ÿ��ͷ�ڵ��б�
    SkipListNode * levelHeadList[SKIP_LIST_MAX_LEVEL];
    
    // ÿ��β�ڵ��б�
    SkipListNode * levelTailList[SKIP_LIST_MAX_LEVEL];
    
    // ��ǰ��߲���
    int currentHighestLevel;
    
    // ���������
    unsigned int randomSeed;
};



// �����к� iValue ��ȵĽڵ㣬��պ�С�� iValue �Ľڵ������·��
void JustLessOrEqualSearchPath(SkipList * pstSkipList, int iValue, std::vector<SkipListNode *> & vecNodePath)
{
    // ȡ��߲�����
    int iLevelIndex = pstSkipList -> currentHighestLevel;
    
    // ִ�в���ѭ�� ...
    for (SkipListNode * pstCurrent = pstSkipList -> levelHeadList[iLevelIndex]; pstCurrent != NULL;)
    {
        // �����ҵ����ڵ��ڴ�����ֵ�Ľڵ� ...
        if (pstCurrent -> type == SLNT_INFINITY_SMALL || (pstCurrent -> type == SLNT_NORMAL_VALUE && pstCurrent -> value < iValue))
        {
            pstCurrent = pstCurrent -> right;
        }
        else
        {
            // �˵��պñȴ���ֵС�Ľڵ�
            if (pstCurrent -> type == SLNT_INFINITY_LARGE || (pstCurrent -> type == SLNT_NORMAL_VALUE && pstCurrent -> value > iValue))
            {
                pstCurrent = pstCurrent -> left;
            }
            
            // ���ڵ����·����
            vecNodePath.push_back(pstCurrent);
            
            // ̽����һ��
            pstCurrent = pstCurrent -> down;
        }
    }
}


// ����
void Insert(SkipList * pstSkipList, int iValue)
{
    // ����·��
    std::vector<SkipListNode *> vecNodePath;
    
    // ��ȡ��ǰֵ�������·��
    JustLessOrEqualSearchPath(pstSkipList, iValue, vecNodePath);
    
    // ��¼�²�ڵ�
    SkipListNode * pstDownNewNode = NULL;
    
    // ִ�в���
    for (int iIndex = static_cast<int>(vecNodePath.size() - 1); true; iIndex --)
    {
        // �����½ڵ㣬�������ҽڵ����
        SkipListNode * pstNewNode   = new SkipListNode(iValue, SLNT_NORMAL_VALUE);
        SkipListNode * pstLeftNode  = NULL;
        SkipListNode * pstRightNode = NULL;
        
        // ȡ���ҽڵ�
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
        
        // ���½ڵ���뵱ǰ�������
        pstLeftNode  -> right = pstNewNode;
        pstRightNode -> left  = pstNewNode;
        
        // ���½ڵ���뵱ǰ�������
        pstNewNode -> left  = pstLeftNode;
        pstNewNode -> right = pstRightNode;
        
        // �½ڵ������²�����
        if (pstDownNewNode != NULL)
        {
            pstDownNewNode -> up   = pstNewNode;
            pstNewNode     -> down = pstDownNewNode;
        }
        
        // Ӳ�������δѡ�������򳬹����������˳�ѭ��
        if (rand_r(&pstSkipList -> randomSeed) % 2)
        {
            break;
        }
        
        // �����²�ڵ��¼
        pstDownNewNode = pstNewNode;
    }
}


// ɾ��
bool Delete(SkipList * pstSkipList, int iValue)
{
    // ����·��
    std::vector<SkipListNode *> vecNodePath;
    
    // ��ȡ��ǰֵ�������·��
    JustLessOrEqualSearchPath(pstSkipList, iValue, vecNodePath);
    
    // ����·�������һ���ڵ�
    int iPathEndIndex = static_cast<int>(vecNodePath.size() - 1);
    
    // ��ɾ���ڵ㲻���ڷ���
    if (vecNodePath[iPathEndIndex] -> type != SLNT_NORMAL_VALUE || vecNodePath[iPathEndIndex] -> value != iValue)
    {
        return false;
    }
    
    // ִ��ɾ��
    for (int iIndex = iPathEndIndex; iIndex >= 0 && vecNodePath[iIndex] -> type == SLNT_NORMAL_VALUE && vecNodePath[iIndex] -> value == iValue; iIndex --)
    {
        // ȡĿ��ڵ�����ҽڵ�
        SkipListNode * pstDstNode   = vecNodePath[iIndex];
        SkipListNode * pstLeftNode  = pstDstNode -> left;
        SkipListNode * pstRightNode = pstDstNode -> right;
        
        // ������ժ��Ŀ��ڵ�
        pstLeftNode  -> right = pstRightNode;
        pstRightNode -> left  = pstLeftNode;
        
        // �����ڴ�
        delete pstDstNode;
        pstDstNode = NULL;
    }
    
    // ɾ���ɹ�
    return true;
}


// ������
bool Exist(SkipList * pstSkipList, int iValue)
{
    // ����·��
    std::vector<SkipListNode *> vecNodePath;
    
    // ��ȡ��ǰֵ�������·��
    JustLessOrEqualSearchPath(pstSkipList, iValue, vecNodePath);
    
    // ȡ·�������һ���ڵ�
    SkipListNode * pstDstNode = vecNodePath[vecNodePath.size() - 1];
    
    // �жϲ����ؽ��
    return pstDstNode -> type == SLNT_NORMAL_VALUE && pstDstNode -> value == iValue;
}



// ���Ա�������
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


// ����
int main()
{
    // ����ֵ
    int iTestValue = 0;
    
    // �����Ե�����
    SkipList stSkipList;
    
    // ���������ʾ
    std::cout << "Input Insert Elements: ";
    
    // ����Ԫ���б���0����
    while (std::cin >> iTestValue)
    {
        if (iTestValue == 0)
        {
            break;
        }
        
        Insert(&stSkipList, iTestValue);
    }
    
    // ����󿴽��
    Traversal(&stSkipList);
    
    // ���ɾ����ʾ
    std::cout << "Input Delete Elements: ";
    
    // ɾ��Ԫ��
    while (std::cin >> iTestValue)
    {
        if (iTestValue == 0)
        {
            break;
        }
        
        Delete(&stSkipList, iTestValue);
    }
    
    // ɾ���󿴽��
    Traversal(&stSkipList);
    
    // �˳�
    return 0;
}


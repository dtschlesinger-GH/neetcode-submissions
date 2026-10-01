/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void AddNewEntry(ListNode* origin, ListNode* sorted) 
    {
        sorted->next = new ListNode(origin->val);
        sorted = sorted->next;
        origin = origin->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* toReturn = new ListNode(0);
        ListNode* head = toReturn;
        
        while (list1 != nullptr || list2 != nullptr) 
        {
            if (list1 == nullptr) 
            {
                cout << "list 1 is null" << endl;
                head->next = list2;
                list2 = list2->next;
            }
            else if (list2 == nullptr) 
            {
                cout << "list 2 is null" << endl;
                head->next = list1;
                list1 = list1->next;
            }
            else if (list1->val < list2->val) 
            {
                cout << "list 1 is less" << endl;
                head->next = list1;
                list1 = list1->next;
            }
            else
            {
                cout << "list 2 is less" << endl;
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }

        return toReturn->next;
    }
};

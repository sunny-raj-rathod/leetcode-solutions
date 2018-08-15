/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void addToResult(ListNode** head, ListNode** ptr, ListNode* newNode)
    {
        if(*head == NULL)
        {
            *head = newNode;
            *ptr = *head;
        }
        else
        {
            (*ptr)->next = newNode;
            *ptr = (*ptr)->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL, *ptr = NULL;
        int carry = 0;
        while(l1 && l2)
        {
            int val = l1->val + l2 -> val + carry;
            carry = val / 10;
            ListNode *newNode = new ListNode(val % 10);
            addToResult(&result, &ptr, newNode);
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            int val = l1->val + carry;
            carry = val / 10;
            ListNode *newNode = new ListNode(val % 10);
            addToResult(&result, &ptr, newNode);
            l1 = l1->next;
        }

        while(l2)
        {
            int val = l2 -> val + carry;
            carry = val / 10;
            ListNode *newNode = new ListNode(val % 10);
            addToResult(&result, &ptr, newNode);
            l2 = l2->next;
        }

        if(carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            addToResult(&result, &ptr, newNode);
        }

        return result;
    }
};

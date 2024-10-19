// dumb, but is fast, oct 2024 beats 98.64%

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    // Function to add two numbers represented by linked lists
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Initialize current node to dummy head of the returning list.
        ListNode *dummyHead = new ListNode(0);
        // Initialize p and q to head of l1 and l2 respectively.
        ListNode *p = l1, *q = l2, *curr = dummyHead;
        // Initialize carry to 0.
        int carry = 0;

        // Loop through lists l1 and l2 until you reach both ends.
        while (p != nullptr || q != nullptr)
        {
            // Set x to node p's value. If p has reached the end of l1, set to 0.
            int x = (p != nullptr) ? p->val : 0;
            // Set y to node q's value. If q has reached the end of l2, set to 0.
            int y = (q != nullptr) ? q->val : 0;
            // Set sum = x + y + carry
            int sum = carry + x + y;
            // Update carry = sum / 10
            carry = sum / 10;
            // Create a new node with the digit value of (sum mod 10) and set it to current node's next, then advance current node to next.
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            // Advance both p and q.
            if (p != nullptr)
                p = p->next;
            if (q != nullptr)
                q = q->next;
        }
        // Check if carry = 1, if so append a new node with digit 1 to the returning list.
        if (carry > 0)
        {
            curr->next = new ListNode(carry);
        }
        // Return dummy head's next node.
        return dummyHead->next;
    }
};
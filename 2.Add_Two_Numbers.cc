struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x)
	: val(x)
	, next(nullptr)
	{}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int flag = 0;
		ListNode *p;
		ListNode* result = new ListNode(0);
		p = result;
		while(l1 != nullptr && l2 != nullptr){
			int temp = (l1 -> val) + (l2 -> val) + flag;
			if(temp/10 > 0){
				flag = 1;
			}else{
				flag = 0;
			}
			l1 = l1->next;
			l2 = l2->next;

			if(p!= nullptr){
				ListNode* head = new ListNode(temp%10);
				p->next = head;
				p = p->next;
			}
		}

		while(l1 != nullptr){
			ListNode* head = new ListNode((l1->val + flag) % 10);
			if((l1->val + flag)/10 > 0)
				flag = 1;
			else
				flag = 0;
			p->next = head;
			p = p->next;
			l1 = l1->next;
		}

		while(l2 != nullptr){
			ListNode* head = new ListNode((l2->val + flag) % 10);
			if((l2->val + flag)/10 > 0)
				flag = 1;
			else
				flag = 0;
			p->next = head;
			p = p->next;
			l2 = l2->next;
		}

		if(flag == 1){
			ListNode* head = new ListNode(1);
			p->next = head;
		}

		return result->next;
	}
};

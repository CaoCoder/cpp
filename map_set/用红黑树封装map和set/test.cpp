
//��������x == date�Ľڵ�

int delc(node* Head, int x)
{
	node* prev = NULL;//previous ��ǰ��
	node* cur = Head;//current ��ǰ��
	while (cur != NULL)
	{
		//����ҵ���ɾ���󷵻�1
		if (cur->date == x)
		{
			//�ı�ָ��
			prev->next = cur->next;

			//ɾ�����
			delete cur;
			cur->next = NULL;//��ʱ��Ϊ�գ�����Ұָ�롣
			return 1;
		}
		else
		{
			prev = cur;//��¼ǰһ�����
			cur = cur->next;//����������һ�����
		}
	}
	//�������ߵ���һ�У�˵��û���ҵ�
	return 0;
}


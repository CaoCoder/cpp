
//遍历查找x == date的节点

int delc(node* Head, int x)
{
	node* prev = NULL;//previous 先前的
	node* cur = Head;//current 当前的
	while (cur != NULL)
	{
		//如果找到了删除后返回1
		if (cur->date == x)
		{
			//改变指向
			prev->next = cur->next;

			//删除结点
			delete cur;
			cur->next = NULL;//及时设为空，避免野指针。
			return 1;
		}
		else
		{
			prev = cur;//记录前一个结点
			cur = cur->next;//继续走向下一个结点
		}
	}
	//代码能走到这一行，说明没有找到
	return 0;
}


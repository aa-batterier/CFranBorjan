int insert(struct array_list *l,int index,void *new)
{
	if (index >= 0 && index < l->n && l->n < CAPACITY)
	{
		void *temp = l->a[index];
		l->a[index] = new;
		for (int i = index+1; i <= n-index; i++)
		{
			void *tmp = l->a[i];
			l->a[i] = temp;
			temp = tmp;
		}
		l->n++;
		return 1;
	}
	return 0;
}

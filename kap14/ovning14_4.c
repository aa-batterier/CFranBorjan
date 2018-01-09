struct node *get_first(struct linked_list *l)
{
	if (l->first != NULL)
		return l->first->data;
	return NULL;
}

struct node *get_last(struct linked_list *l)
{
	if (l->first != NULL)
	{
		struct node *p = l->first;
		while (p->next != NULL)
			p = p->next;
		return p->data;
	}
	return NULL;
}

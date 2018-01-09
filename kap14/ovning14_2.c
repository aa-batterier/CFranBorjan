void *remove_last(struct array_list *l)
{
	if (l->n > 0)
	{
		l->n--;
		return l->a[l->n];
	else
		return NULL;
}

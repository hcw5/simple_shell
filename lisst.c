#include "shell.h"

/**
 * populate_node - add node to List
 * @h: Head node
 * @strng: String
 * @nmber: Index
 * Return: List size
 */
lst_m *populate_node(lst_m **h, const char *strng, int nmber)
{
	lst_m *addh;

	if (!h)
		return (NULL);
	addh = malloc(sizeof(lst_m));
	if (!addh)
		return (NULL);
	mmry_arn((void *)addh, 0, sizeof(lst_m));
	addh->nmber = nmber;
	if (strng)
	{
		addh->strng = strngclone(strng);
		if (!addh->strng)
		{
			free(addh);
			return (NULL);
		}
	}
	addh->next = *h;
	*h = addh;
	return (addh);
}

/**
 * endnode_add - add NOde to the end of list
 * @h: Head node
 * @strng: Strng
 * @nmber: Index
 * Return: List size
 */
lst_m *endnode_add(lst_m **h, const char *strng, int nmber)
{
	lst_m *sect, *addn;

	if (!h)
		return (NULL);

	sect = *h;
	addn = malloc(sizeof(lst_m));
	if (!addn)
		return (NULL);
	mmry_arn((void *)addn, 0, sizeof(lst_m));
	addn->nmber = nmber;
	if (strng)
	{
		addn->strng = strngclone(strng);
		if (!addn->strng)
		{
			free(addn);
			return (NULL);
		}
	}
	if (sect)
	{
		while (sect->next)
			sect = sect->next;
		sect->next = addn;
	}
	else
		*h = addn;
	return (addn);
}

/**
 * lststr_prnt - Prints str Element
 * @hd: Head node pointer
 * Return: List size
 */
size_t lststr_prnt(const lst_m *hd)
{
	size_t a = 0;

	while (hd)
	{
		strngin(hd->strng ? hd->strng : "(nil)");
		strngin("\n");
		hd = hd->next;
		a++;
	}
	return (a);
}

/**
 * indxnode_del - delete NODE at the indx
 * @h: Head node
 * @ind: The index
 * Return: 1
 */
int indxnode_del(lst_m **h, unsigned int ind)
{
	unsigned int a = 0;
	lst_m *sect, *tdtd;

	if (!h || !*h)
		return (0);

	if (!ind)
	{
		sect = *h;
		*h = (*h)->next;
		free(sect->strng);
		free(sect);
		return (1);
	}
	sect = *h;
	while (sect)
	{
		if (a == ind)
		{
			tdtd->next = sect->next;
			free(sect->strng);
			free(sect);
			return (1);
		}
		a++;
		tdtd = sect;
		sect = sect->next;
	}
	return (0);
}

/**
 * freelst - Liberates all nodes
 * @pthd: Head node
 * Return: void
 */
void freelst(lst_m **pthd)
{
	lst_m *sect, *nexn, *h;

	if (!pthd || !*pthd)
		return;
	h = *pthd;
	sect = h;
	while (sect)
	{
		nexn = sect->next;
		free(sect->strng);
		free(sect);
		sect = nexn;
	}
	*pthd = NULL;
}

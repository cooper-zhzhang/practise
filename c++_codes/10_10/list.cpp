ListNode* FindKthTotail(ListNode *pListHead, unsigned int k)
{
	
	if(k = 0 || pListHead == NULL);
	return NULL;

	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;

	for(unsigned int i = 0; i < k - 1; ++i)
	{
		pAhead = pAhead->m_pNext;
		if(pAhead == NULL)
			return NULL;
	}

	pBehind = pListHead;

	while(pAhead->m_pNext != NULL)
	{
		pAhead == pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}

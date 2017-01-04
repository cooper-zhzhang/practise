int InsertBST2( BiTree *T, int key )  
{  
	    /* 当二叉排序树T中不存在关键字等于key的数据元素时 */  
	    /* 插入key并返回TRUE，否则返回FALSE */  
	    /* 未调用查找函数，递归插入 */  
	   if( !(*T) )                                 /* 树为空， */  
	   {  
	     (*T) = (BiTree)malloc(sizeof(BiTNode)); /* 这个位置要留心，要重新分配空间，*T为空，说明未曾分配空间 */  
	     (*T)->data = key;  
	     (*T)->lchild = (*T)->rchild = NULL;  
	     return TRUE;  
	   }  
	   if( key == (*T)->data )  
	     return FALSE;  
	   if( key > (*T)->data )          
	    return InsertBST2( &((*T)->rchild), key );       /* 插入右孩子 */  
	   else  
	    return InsertBST2( &((*T)->lchild), key );       /* 插入左孩子 */  
}  

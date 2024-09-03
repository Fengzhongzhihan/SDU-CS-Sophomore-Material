int a[6];
for (int i = 0;i < 6;i++)
	cin>>a[i];

for (int i = 0;i < 6;i++) {
	if (!(i > 0 && i < 7) explode_bomb();
	for (int j = i + 1;j < 6;j++)
		if (a[i] == a[j]) explode_bomb();
}

chain c = {0x0fd, 0x2d5, 0x12d, 0x3e5, 0x0d4, 0x1b0};
chainNode res[6];
for (int i = 0;i < 6;i++) {
	chainNode *node = c.firstNode;
	for (int j = 1;j < a[i];j++)
		node = node->next;
	res[i] = node;
}

chainNode *node = res[0];
for (int i = 1;i < 6;i++) 
{
	node->next = res[i];
	node = res[i];
}
node->next = null;

if (ID & 1)
 {
	node = c.firstNode;
	for (int i = 0;i < 5;i++)
    {
        if (node->element < node->next->element)
			explode_bomb();
        node=node->next;
    }
}
else 
{
	node = c.firstNode;
	for (int i = 0;i < 5;i++)
    {
        if (node->element >node->next->element)
			explode_bomb();
        node=node->next;
    }
}

struct node
{
	int count;
	node *left, *right;

	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}

	node* insert(int l, int r, int w);
};
node * node::insert(int l, int r, int w)
{
	if(l <= w && w < r)
	{
		// With in the range, we need a new node
		if(l+1 == r)
		{
			return new node(this->count+1, null, null);
		}

		int m = (l+r)>>1;

		return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
	}

	// Out of range, we can use previous tree node.
	return this;
}
node *root[N];


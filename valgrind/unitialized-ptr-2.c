void foo(int * a) {
	a[1] = 10;
}

int main() {
	int * a;
	foo(a);
	return 0;
}
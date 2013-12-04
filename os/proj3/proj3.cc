do {
	r = next page request
	if(r is already in memory) {
		do nothing or handle this;
	}
	else if(there exists an empty page frame 'f' for this page request) {
		pgFrame[f] = r;
	}
	else { //page fault
		p = pageToEvict();
		move pageRef[p] to bottom part of pageRef
		r = p;
	}
} while(there are more pages in reference string);
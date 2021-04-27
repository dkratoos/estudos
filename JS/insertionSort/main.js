function insercao (array) {
	console.log('Old Array -> ', array)
	const tamanho = array.length

	let i, j, x;

	for (i=2; i <= tamanho - 1; i++) { // n - 1
		x = array[i] 											// n - 1
		j = i - 1;												// n - 1

		while (j > 0 && x < array[j]) {   // 1 + 2 + 3 ... + n - 1
			array[j+1] = array[j]						// 1 + 2 + 3 ... + n - 1
			j--;														// 1 + 2 + 3 ... + n - 1
		}

		array[j+1] = x                    // n - 1
	}
	console.log('New array -> ', array)
}

insercao([20, 10, 25, 15, 5 ])
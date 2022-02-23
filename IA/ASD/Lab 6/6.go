//Eu m am gandit tot la acest algoritm, dar din cauza ca trebuie unul diferit
//Desi este mult mai incet, putem parcurge de 2 ori lista, si de fiecare data sa gasim minimul, dar a doua oara si ignoram primul minim

//Implementari algoritmi in go

func minslow(arr []int) (int,int) {
	min1,min2 := 0,0 //le facem int
	if arr[0]<arr[1] {
		min1=arr[0]
		min2=arr[1]
	} else {
		min1=arr[1]
		min2=arr[0]
	}

	for _, v := range arr {
		if v<min1 {
			min1=v
		}
	}
	for _, v := range arr {
		if v<min2 && v!=min1 {
			min2=v
		}
	}
	return min1,min2
}



func f_c(arr []int) []int {
	fc := make([]int, len(arr))
	fc[0]=arr[0]
	for i:=1; i< len(arr); i++ {
		fc[i]=fc[i-1]+arr[i]
	}
	return fc
}

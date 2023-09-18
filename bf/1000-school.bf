			     			Cell c0 = 0
> ++++ ++++ + 				Cell c1 = 9

[        					Start loop
< ++++ ++++ +      			Add 9 to c0
> -      					Subtract 1 from c1
]        					End loop

< ++                        Add 2 to c0

.        				    Print the value of cell c0 {83: "S"}

> ++						Cell c1 = 2

[        					Start loop
	< ++++ ++++				Add 8 to c0
	> -      				Subtract 1 from c1
]        					End loop

< .							Print the value of cell c0 {99: "c"}

++++ +						Add 5 to c0

.							Print the value of cell c0 {104: "h"}

++++ +++					Add 7 to c0

..							Print the value of cell c0 twice {111: "o"}

---							Subtract 3 from c0

.							Print the value of cell c0 {108: "l"}

> ++++ ++++ ++				Add 12 to c1

.							Print the value of cell c1 which is the newline character

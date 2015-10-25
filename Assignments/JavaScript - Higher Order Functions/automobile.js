	function Automobile( year, make, model, type ){
		this.year = year; //integer (ex. 2001, 1995)

		this.make = make; //string (ex. Honda, Ford)

		this.model = model; //string (ex. Accord, Focus)

		this.type = type; //string (ex. Pickup, SUV)

	}

	var automobiles = [
		new Automobile(1995, "Honda", "Accord", "Sedan"),
		new Automobile(1990, "Ford", "F-150", "Pickup"),
		new Automobile(2000, "GMC", "Tahoe", "SUV"),
		new Automobile(2010, "Toyota", "Tacoma", "Pickup"),
		new Automobile(2005, "Lotus", "Elise", "Roadster"),
		new Automobile(2008, "Subaru", "Outback", "Wagon")

		];


/* print out an unsorted array just to check the sorting actually works */
console.log("");
console.log("Unsorted car array: ");
printArr(automobiles);
console.log("");

 
/*This function sorts arrays using an arbitrary comparator. You pass it a comparator and an array of objects appropriate for that comparator and it will return a new array which is sorted with the largest object in index 0 and the smallest in the last index*/
function sortArr(comparator, array){

	var sortedArr = array.slice();
	var temp;
   
   /* looping through the array to check and compare and move positions as necessary */
    for(var i = 0; i < sortedArr.length-1; i++){
        for(var j = i+1; j < sortedArr.length; j++){
			
			//run the compare and bubble sort
            if(!comparator(sortedArr[j], sortedArr[i])){
                temp = sortedArr[i];
                sortedArr[i] = sortedArr[j];
                sortedArr[j] = temp;
			}
		}	
	}
	return sortedArr;  //returns the sorted array based on what comparator you use
}

/*A comparator takes two arguments and uses some algorithm to compare them. If the first argument is larger or greater than the 2nd it returns true, otherwise it returns false. Here is an example that works on integers*/
function exComparator( int1, int2){
    if (int1 > int2){
        return true;
    } else {
        return false;
    }
}


/*This compares two automobiles based on their year. Newer cars are "greater" than older cars.*/
function yearComparator(auto1, auto2){
    
	if (auto1.year > auto2.year){
		return true;
    }
	
	else 
        return false;

}

/*This compares two automobiles based on their make. It should be case insensitive and makes which are alphabetically earlier in the alphabet are "greater" than ones that come later.*/
function makeComparator(auto1, auto2){
	
	/* converts the make to lower case to make it case insensitive */
	var car1 = auto1.make.toLowerCase();
    var car2 = auto2.make.toLowerCase();
	
	/* compare the makes together */
    if (car1 > car2){
        return true;
    } 
	
	else 
		return false;
 
}


/*This compares two automobiles based on their type. The ordering from "greatest" to "least" is as follows: roadster, pickup, suv, wagon, (types not otherwise listed). It should be case insensitive. If two cars are of equal type then the newest one by model year should be considered "greater".*/
function typeComparator(auto1, auto2){

	
	var car1 = auto1.type.toLowerCase();
	var car2 = auto2.type.toLowerCase();
	
	if (car1 == "roadster" && car2 !="roadster")
		return false;
	
	else if (car1 == "pickup" && car2 != "roadster" && car2 != "pickup")
		return false;
	
	else if (car1 == "suv" && car2 != "roadster" && car2 != "pickup" && car2 != "suv")
		return false;
	
	else if (car1 == "wagon" && car2 != "roadster" && car2 != "pickup" && car2 != "suv" && car2 != "wagon")
		return false;
	
	else if (car1 == car2){
		if (yearComparator(auto1, auto2))
			return false;
		else 
			return true;
	}

	else
		return true;
	
}


/*Your program should output the following to the console.log, including the opening and closing 5 stars. All values in parenthesis should be replaced with appropriate values. Each line is a seperate call to console.log.

Each line representing a car should be produced via a logMe function. This function should be added to the Automobile class and accept a single boolean argument. If the argument is 'true' then it prints "year make model type" with the year, make, model and type being the values appropriate for the automobile. If the argument is 'false' then the type is ommited and just the "year make model" is logged.

*****
The cars sorted by year are:
(year make model of the 'greatest' car)
(...)
(year make model of the 'least' car)

The cars sorted by make are:
(year make model of the 'greatest' car)
(...)
(year make model of the 'least' car)

The cars sorted by type are:
(year make model type of the 'greatest' car)
(...)
(year make model type of the 'least' car)
*****

As an example of the content in the parenthesis:
1990 Ford F-150 */

/* This is necessary to test to make sure they print out correctly */

function printArr(array){
	
    for(var i = 0; i < array.length; i++){
        var car = array[i];
        console.log(car.year + " " + car.make + " " + car.model + " " + car.type);  
    }

}
	console.log("We sorted the list of cars for you! (hopefully) ");
	console.log("");
	
	console.log("The cars sorted by YEAR are:");
	console.log("");	
	var yearSort = sortArr(yearComparator, automobiles);
	printArr(yearSort);
	console.log("");
	
	console.log("The cars sorted by MAKE are:");
	console.log("");
	var makeSort = sortArr(makeComparator, automobiles);
	printArr(makeSort);
	console.log(""); 
	
	console.log("The cars sorted by TYPE are: ");
	console.log("");
	var typeSort = sortArr(typeComparator, automobiles);
	printArr(typeSort);
	console.log("");

	console.log("Thats all folks!");


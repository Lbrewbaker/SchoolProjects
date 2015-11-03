//Building the table
function buildTable(){
	
	var newTable = document.createElement("table");
	
	for(var i = 0; i < 4; i++){
		var tbRow = document.createElement("tr");
		var tbData1 = document.createElement("td");
		var tbData2 = document.createElement("td");
		var tbData3 = document.createElement("td");
		var tbData4 = document.createElement("td");

		if(i == 0){
			var textNd1 = document.createTextNode("Header 1");
			var textNd2 = document.createTextNode("Header 2");
			var textNd3 = document.createTextNode("Header 3");
			var textNd4 = document.createTextNode("Header 4");
		}
		
		else if(i == 1){
			var textNd1 = document.createTextNode("1, 1");
			var textNd2 = document.createTextNode("2, 1");
			var textNd3 = document.createTextNode("3, 1");
			var textNd4 = document.createTextNode("4, 1");
		}
		
		else if(i == 2){
			var textNd1 = document.createTextNode("1, 2");
			var textNd2 = document.createTextNode("2, 2");
			var textNd3 = document.createTextNode("3, 2");
			var textNd4 = document.createTextNode("4, 2");
		}
		
		else if(i == 3){
			var textNd1 = document.createTextNode("1, 3");
			var textNd2 = document.createTextNode("2, 3");
			var textNd3 = document.createTextNode("3, 3");
			var textNd4 = document.createTextNode("4, 3");
		}	
		
		tbData1.appendChild(textNd1);
		tbData2.appendChild(textNd2);
		tbData3.appendChild(textNd3);
		tbData4.appendChild(textNd4);

		tbRow.appendChild(tbData1);
		tbRow.appendChild(tbData2);
		tbRow.appendChild(tbData3);
		tbRow.appendChild(tbData4);

		newTable.appendChild(tbRow);
	}
    document.getElementById("tableHere").appendChild(newTable);
	newTable.setAttribute("border", 3);
	return newTable;
}

function initTable(table){
	table.children[1].children[0].style.borderStyle = "solid";
	table.children[1].children[0].style.borderWidth = "thick";
	return table.children[1].children[0];
}


var table = buildTable();
var currentCell = initTable(table);

//change cell border to thin
function changeCell(cell){
    	cell.style.borderWidth = "thin";
		cell.style.backgroundColor = "yellow";
}

//                   Button section                       //




//down button


function goDown(table, cell){
	var newCell;
	
		
	if(cell.parentNode == table.children[3]){
		alert("At the bottom!");
	}
	
	else if(cell == cell.parentNode.children[0]){
		console.log(cell.parentNode.children[0]);
		newCell = cell.parentNode.nextElementSibling.children[0];
	}
	
	else if(cell == cell.parentNode.children[1]){
		console.log(cell.parentNode.children[1]);
		newCell = cell.parentNode.nextElementSibling.children[1];
	}
	
	else if(cell == cell.parentNode.children[2]){
		console.log(cell.parentNode.children[2]);
		newCell = cell.parentNode.nextElementSibling.children[2];
	}
	
	else if(cell == cell.parentNode.children[3]){
		console.log(cell.parentNode.children[3]);
		newCell = cell.parentNode.nextElementSibling.children[3];
	}
	
	changeCell(cell);
	newCell.style.borderWidth = "thick";
	return newCell;
}

document.getElementById("down").addEventListener("click", function(){
	currentCell = goDown(table, currentCell);
});



//up button


function goUp(table, cell){
	var newCell;
	
	if(cell.parentNode == table.children[1]){
		alert("At the top!");
	}
	
	else if(cell == cell.parentNode.children[3]){
		console.log(cell.parentNode.children[3]);
		newCell = cell.parentNode.previousElementSibling.children[3];
	}

	else if(cell == cell.parentNode.children[2]){
		console.log(cell.parentNode.children[2]);
		newCell = cell.parentNode.previousElementSibling.children[2];
	}
	
	else if(cell == cell.parentNode.children[1]){
		console.log(cell.parentNode.children[1]);
		newCell = cell.parentNode.previousElementSibling.children[1];
	}
	
	else if(cell == cell.parentNode.children[0]){
		console.log(cell.parentNode.children[0]);
		newCell = cell.parentNode.previousElementSibling.children[0];
	}

	
	changeCell(cell);
	newCell.style.borderWidth = "thick";
	return newCell;
}

document.getElementById("up").addEventListener("click", function(){
	currentCell = goUp(table, currentCell);
});

//right button

function goRight(table, cell){
	var newCell;
	
	if(cell == cell.parentNode.children[3]){
		alert("Too far Right!");
	}
		
	if(cell == cell.parentNode.children[0]){
        console.log(cell);
        newCell = cell.parentNode.children[1];
	}
	
	else if(cell == cell.parentNode.children[1]){
		console.log(cell);
		newCell = cell.parentNode.children[2];
	}
	
	else if(cell == cell.parentNode.children[2]){
		console.log(cell);
		newCell = cell.parentNode.children[3];
	}

	
	changeCell(cell);
	newCell.style.borderWidth = "thick";
	return newCell;
	
}

document.getElementById("right").addEventListener("click", function(){
	currentCell = goRight(table, currentCell);
});



//left button

function goLeft(table, cell){
	
	var newCell;
	
	if(cell == cell.parentNode.children[0]){
		alert("Too far Left!");
	}
	
	if(cell == cell.parentNode.children[1]){
        console.log(cell);
        newCell = cell.parentNode.children[0];
	}
	
	else if(cell == cell.parentNode.children[2]){
		console.log(cell);
		newCell = cell.parentNode.children[1];
	}
	
	else if(cell == cell.parentNode.children[3]){
		console.log(cell);
		newCell = cell.parentNode.children[2];
	}

	changeCell(cell);
	newCell.style.borderWidth = "thick";
	return newCell;
}



document.getElementById("left").addEventListener("click", function(){
	currentCell = goLeft(table, currentCell);
});


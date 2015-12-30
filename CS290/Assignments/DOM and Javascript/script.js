function buildTable() {
	
   var newTable = document.createElement("table");

   
   //Var I = Rows
   //Var J = columns
    for (var i = 0; i < 4; i++) {
        var tr = document.createElement('tr');

        for (var j = 0; j < 4; j++) {
            var td = document.createElement('td');
			
			if (i == 0 && j != 4){
				td.appendChild(document.createTextNode("Header "))
				td.appendChild(document.createTextNode((j+1)))
				tr.appendChild(td)

			}
			
			else {
                td.appendChild(document.createTextNode(i))
				td.appendChild(document.createTextNode(", "))
				td.appendChild(document.createTextNode((j+1)))
				tr.appendChild(td)
            }
			

        }

       newTable.appendChild(tr);
    }
	
    document.getElementById("tableHere").appendChild(newTable);
	newTable.setAttribute("border", 3);
	newTable.style.width = '50%';
    return newTable;
}

function initTable(table){
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
		newCell = cell.parentNode.nextElementSibling.children[0];
	}
	
	else if(cell == cell.parentNode.children[1]){
		newCell = cell.parentNode.nextElementSibling.children[1];
	}
	
	else if(cell == cell.parentNode.children[2]){
		newCell = cell.parentNode.nextElementSibling.children[2];
	}
	
	else if(cell == cell.parentNode.children[3]){
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
		newCell = cell.parentNode.previousElementSibling.children[3];
	}

	else if(cell == cell.parentNode.children[2]){
		newCell = cell.parentNode.previousElementSibling.children[2];
	}
	
	else if(cell == cell.parentNode.children[1]){
		newCell = cell.parentNode.previousElementSibling.children[1];
	}
	
	else if(cell == cell.parentNode.children[0]){
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
        newCell = cell.parentNode.children[1];
	}
	
	else if(cell == cell.parentNode.children[1]){
		newCell = cell.parentNode.children[2];
	}
	
	else if(cell == cell.parentNode.children[2]){
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
        newCell = cell.parentNode.children[0];
	}
	
	else if(cell == cell.parentNode.children[2]){
		newCell = cell.parentNode.children[1];
	}
	
	else if(cell == cell.parentNode.children[3]){
		newCell = cell.parentNode.children[2];
	}

	changeCell(cell);
	newCell.style.borderWidth = "thick";
	return newCell;
}



document.getElementById("left").addEventListener("click", function(){
	currentCell = goLeft(table, currentCell);
});

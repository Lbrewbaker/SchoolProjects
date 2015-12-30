document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
	document.getElementById('addWorkout').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var payload = {};

		payload.name = document.getElementById('name').value;
		payload.reps = document.getElementById('reps').value;
		payload.weight = document.getElementById('weight').value;
		payload.date = document.getElementById('date').value;
		payload.units = document.getElementById('units').value;
		payload.workout = true;

		req.open('POST', '/', true);
		req.setRequestHeader('Content-Type', 'application/json');
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
				var response = JSON.parse(req.responseText);

				var mainTable = document.getElementById('mainTable');
				var newRow = document.createElement('tr');
				newRow.setAttribute('id', 'row' + response.id);
				mainTable.appendChild(newRow);

				for (var i = 0; i < 6; i++){
					var newCell = document.createElement('td');
					newRow.appendChild(newCell);
				}

				newRow.children[0].textContent = response.name;
				newRow.children[1].textContent = response.reps;
				newRow.children[2].textContent = response.weight;
				newRow.children[3].textContent = response.date;
				newRow.children[4].textContent = response.lbs;

				var modEx = document.createElement('form');
				newRow.children[5].appendChild(modEx);
				modEx.setAttribute('method', 'post');

				for (var i = 0; i < 3; i++){
					var newInput = document.createElement('input');
					modEx.appendChild(newInput);
				}

				modEx.children[0].setAttribute('type', 'hidden');
				modEx.children[0].setAttribute('name', 'id');
				modEx.children[0].setAttribute('value', response.id);

				modEx.children[1].setAttribute('type', 'submit');
				modEx.children[1].setAttribute('name', 'edit');
				modEx.children[1].setAttribute('value', 'Edit');

				modEx.children[2].setAttribute('class', 'deleteWorkout');
				modEx.children[2].setAttribute('type', 'submit');
				modEx.children[2].setAttribute('name', 'delete');
				modEx.children[2].setAttribute('value', 'Delete');
				modEx.children[2].addEventListener('click', delFunction, true);

			} else {
				console.log("Error in network request: " + request.statusText);
			}
		});
		req.send(JSON.stringify(payload));
		event.preventDefault();
	});

	var deleteEx = document.getElementsByClassName('deleteWorkout');

	var delFunction = function(event){
		var req = new XMLHttpRequest();

		var payload = {};
		payload.id = this.parentNode.firstElementChild.value;
		payload.del = true;

		req.open('POST', '/', false);
		req.setRequestHeader('Content-Type', 'application/json');
		req.send(JSON.stringify(payload));
		event.preventDefault;
		var response = JSON.parse(req.responseText);
		var delParent = document.getElementById('row' + response.id).parentNode;
		delParent.removeChild(document.getElementById('row' + response.id));
	};

	for(var i = 0; i < deleteEx.length; i++){
		deleteEx[i].addEventListener('click', delFunction);
	}
}
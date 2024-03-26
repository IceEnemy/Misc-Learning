<script>
    let firstName = 'Bruce';
    let lastName = 'Wayne';
    $: fullName = `${firstName} ${lastName}`;

    $: {
        const greet = `Hello ${firstName} ${lastName}`;
        console.log(greet);
    }
    let items =[
        {
            id: 1,
            title: 'TV',
            price: 100
        },
        {
            id: 2,
            title: 'Phone',
            price: 200
        },
        {
            id: 3,
            title: 'Laptop',
            price: 300
        }
    ]
    $: total = items.reduce((total, curr) => (total = total + curr.price), 0);

    let volume = 0
    $: if(volume < 0){
        alert('Volume is too low');
        volume = 0;
    }
    else if (volume > 20){
        alert('Volume is too high');
        volume = 20;
    }
</script>

<main>
    <h1>Reactive Declarations</h1>

    <h2>Current volume {volume}</h2>
    <button on:click={() => volume+=2}>Increase Volume</button>
    <button on:click={() => volume-=2}>Decrease Volume</button>

    <button on:click={() => {
        firstName = 'Clark';
        lastName = 'Kent';
    }}>Change Name</button>

    <h2>{firstName} {lastName}</h2>
    <h2>{fullName}</h2>

    <button on:click={() => (items = [...items, { id:4, title: 'Keyboard', price:50}])}>Add item</button>

    <h2>
        Total - {items.reduce((total, curr) => (total = total + curr.price), 0)}
    </h2>
    <h2>Total - {total}</h2>


</main>

<style>

	main {
		text-align: center;
		padding: 1em;
		max-width: 240px; 
		margin: 0 auto;
	}

	h1 {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}

	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}
</style>
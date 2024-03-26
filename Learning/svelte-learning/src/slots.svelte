<script>
    import Card from './components/Card.svelte';
    import Card2 from './components/NamedSlots.svelte'
    import NameList from './components/NameList.svelte'
</script>

<main>
    <h1>Slots</h1>
    <NameList>
        <h3 slot='hero' let:firstName let:lastName>
            {firstName} {lastName}
        </h3>
    </NameList>

    <NameList>
        <h3 slot='hero' let:firstName let:lastName>
            {lastName}, {firstName}
        </h3>
    </NameList>
        
    <NameList>
        <h3 slot='hero' let:firstName let:lastName>
            {firstName}
        </h3>
    </NameList>
    <div id="card-container">
        <Card>
            Card Content
        </Card>

        <Card>
            <h2>Card Content</h2>
        </Card>

        <Card>
            <img src="https://placekitten.com/300/200" alt="Kitten" />
        </Card>

        <Card></Card>

        <Card2>
            <div slot='header'>
                <h2>Header</h2>
            </div>
            <div slot='content'>
                <img src="https://placekitten.com/200/200" alt="Kitten" />
            </div>
            <div slot='footer'>
                <button>Cat Button</button>
            </div>
        </Card2>
        <Card2>
            <div slot='header'>
                <h2>Header</h2>
            </div>
            <div slot='content'>
                <img src="https://placekitten.com/150/200" alt="Kitten" />
            </div>
        </Card2>
    </div>
    
</main>
    
<style>
    img {
        width: 100%;
    }
	main {
		text-align: center;
		padding: 1em;
		max-width: 240px; 
		margin: 0 auto;
        /* display: flex;
        flex-wrap: wrap;
        gap: 20px; */
	}

    #card-container {
        display: flex;
        flex-wrap: wrap;
        justify-content: center;
        gap: 20px;
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
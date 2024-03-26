<script>
    import Greet from "./components/greet.svelte";
    const name = 'me';
    const condition = 'rn';
	const obj = {
		name: 'Ice',
		heroName: 'Enemy'
	}
</script>

<main>
    <h1>Playing With Components!</h1>
    <Greet/>
    <Greet name='Bruce' heroName='Batman'/>
    <Greet name='Clark' heroName='Superman'/>
    <Greet name='Diana' heroName='WonderWoman'/>
    <Greet name={name} heroName={condition}/>
	<Greet name={obj.name} heroName={obj.heroName}/>
	<Greet {...obj}/>
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
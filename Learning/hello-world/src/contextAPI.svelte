<script>
    import { setContext } from "svelte";
    import ComponentC from "./components/componentC.svelte"

    const userName = 'IceEnemy';
    setContext('username-context',userName)
</script>

<main>
    <h1>API</h1>

    <h2>App component username - {userName}</h2>
    <ComponentC/>
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
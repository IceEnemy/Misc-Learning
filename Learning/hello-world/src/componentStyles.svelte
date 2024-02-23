<script>
    import ChildStyles from './components/ChildStyles.svelte'
</script>

<main>
    <h1>Styling</h1>
    <h4>App Component text</h4>
    <h3>App Component - global style</h3>
    <ChildStyles />
</main>

<style>
    h4{
        color: orange;
    }

    :global(h3){
        color: blue;
    }

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
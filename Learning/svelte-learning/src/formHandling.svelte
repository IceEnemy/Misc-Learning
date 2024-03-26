<script>
    const formValues = 
    {
        name: '',
        profileSummary: '',
        country: '',
        jobLocation: [],
        remoteWork: false,
        skillSet: [],
        yearOfExperience: ''
    }
    const intValues ={
        num: 0
    }

    function submitForm(event){
        // event.preventDefault();
        console.log(formValues);
        console.log(intValues);
    }
</script>

<main>
    <h1>Form Handling</h1>
    <div>
        <pre>
            {JSON.stringify(formValues, null, 2)}
        </pre>
        <pre>
            {JSON.stringify(intValues, 0, 2)}
        </pre>
    </div>

    <form on:submit|preventDefault={submitForm}>
        <div>
            <label for="name">Name</label>
            <input type="text" id="name" bind:value={formValues.name}>
            <label for="num">Num</label>
            <input type="number" id="num" bind:value={intValues.num}>
        </div>

        <div>
            <label for="profile">Profile Summary</label>
            <textarea id="profile" bind:value={formValues.profileSummary}/>
        </div>

        <div>
            <label for="country">Country</label>
            <select id="country" bind:value={formValues.country}>
                <option value="">Select a country</option>
                <option value="India">India</option>
                <option value="USA">USA</option>
                <option value="UK">UK</option>
            </select>
        </div>

        <div>
            <label for="jobLocation">Job Location</label>
            <select id="jobLocation" bind:value={formValues.jobLocation} multiple>
                <option value="">Select a country</option>
                <option value="India">India</option>
                <option value="USA">USA</option>
                <option value="UK">UK</option>
            </select>
        </div>

        <div>
            <input type="checkbox" id="remoteWork" bind:checked={formValues.remoteWork}>
            <label for="remoteWork">Open to Remote Work?</label>
        </div>

        <div>
            <h2>Skill set</h2>
            <input type="checkbox" id="html" value = "html" bind:group={formValues.skillSet}>
            <label for="html">HTML</label>
            <input type="checkbox" id="css" value = "css" bind:group={formValues.skillSet}>
            <label for="css">CSS</label>
            <input type="checkbox" id="javascript" value = "javascript" bind:group={formValues.skillSet}>
            <label for="javascript">JavaScript</label>
        </div>
        
        <div>
            <h2>Years of Experience</h2>
            <input type="radio" id="0-2" value ="0-2" bind:group={formValues.yearOfExperience}>
            <label for="0-2">0-2</label>
            <input type="radio" id="3-5" value ="3-5" bind:group={formValues.yearOfExperience}>
            <label for="3-5">3-5</label>
            <input type="radio" id="6-10" value ="6-10" bind:group={formValues.yearOfExperience}>
            <label for="6-10">6-10</label>
            <input type="radio" id="10+" value ="10+" bind:group={formValues.yearOfExperience}>
            <label for="10+">10+</label>
        </div>

        <div>
            <button>Submit</button>
        </div>
    </form>
</main>

<style>
    input + label {
       display: inline-flex; 
    }

	main {
		/* text-align: center; */
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
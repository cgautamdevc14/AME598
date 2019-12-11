# Weather Application using JavaScript
This project is intended to get the BASIC weather information of a particular city by using OpenWeatherMap API and JavaScript.

## Prerequisites

In this section, we will discuss the basic components that we need in order to make the weather application.

### Tools

I am going to use the following tools:

-	Sublime Text (you can use whatever editor you want)
-	XAMPP (Optional; for running the webpage locally; you can run the application by opening the index.html page in the web-browser)
If you want to use Sublime Text, go to the following link in order to download it:

>	https://www.sublimetext.com/3
>	

Make sure to download the latest version!

### Programming Language(s)

For setting up, we would require the following:

-	JavaScript (for programming the core of weather app)
-	HTML (front-end; for the general client end page)
-	CSS (for styles)
We will discuss each one of them later in the article, but first, we have to look at the API that is required for getting the weather updates.

### OpenWeatherMap API
For making the weather application, we are going to use the API provided by the following service:
>	OpenWeatherMap 

In order to get the weather updates, we need to sign-up to OpenWeatherMap’s service. For that, go to the following link and sign-up:
>	https://home.openweathermap.org/users/sign_up
>	

After signing-up, you should copy the API key into the Text document by going to the following link:
>	https://home.openweathermap.org/api_keys
>	

If you do not have any API key there, make sure to generate one. The option of generating the API key is available on the same link given above.

Now that we have done the preliminary steps, it is time to dive into the coding part of this application.

## Designing Weather App
First make the following three files in a folder:
-	index.html (file for writing the HTML code)
-	index.js (file for writing the JavaScript code)
-	style.css (file for prettifying the webpage using CSS)

Once you create the aforementioned files, you now need to add the following code in index.html file:
```html
<!DOCTYPE html>
<html lang="en" >

<head>
  <meta charset="UTF-8">
  <title>Weather Application</title>
  
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/normalize/5.0.0/normalize.min.css">

  
      <link rel="stylesheet" href="css/style.css">

  
</head>

<body>

  <div class="container">
  <header class="header">
    <div class="search">
      <input type="text" placeholder="Enter City Name" id="search-txt">
      <a id="search-btn" href="#"><i class="fas fa-search"></i></a>
    </div>
  </header>

  <main id="main">
    
    <div class="city-icon">
      <div class="city-icon-holder">
      <div id="city-name"></div>
      <img src="" alt="" id="icon">
        </div>
    </div>
    
    <div class="temperature">
      <div id="temp"></div>
    </div>
    
    <div class="humidity">
      <div id="humidity-div"></div>
    </div>
    
  </main>
  
</div>
  <script src='https://use.fontawesome.com/releases/v5.0.13/js/all.js'></script>

  

    <script  src="js/index.js"></script>



</body>

</html>

```
The above code has the following important features:
-	**src="js/index.js"**: We added the index.js file right at the end of the body section. In this project, I have made a different JavaScript folder with the name **js**; however, it is not mandatory.
-	The code is divided into two chunks: header, and the main. The parent of both these chunks is the div tag with the class name **container**.
-	Right at the end of the **head** tag, the **css** (named style.css) file is linked in order to prettify the HTML.

The code of **style.css** file is given as follow:
```css
body{
  background-color: #eee;
}

.container{
  width: 500px;
  height: 300px;
  margin:25vh auto;
  border-radius: 25px;
  box-shadow: 0 20px 40px 0px rgba(0,0,0,0.3)
}

.header {
  height: 20%;
  background-color: #FF9800;
  border-top-left-radius: 25px;
  border-top-right-radius: 25px;
  text-align: center;
  position:relative;
}

#temp, #humidity-div {
  font-family: "Courier New";
  font-weight: bold;
  font-size: 60px;
  color: #fff;
  position: absolute;
  left: 50%;
  top: 50%;
  -webkit-transform: translate(-50%, -50%);
          transform: translate(-50%, -50%);
}

.city-icon-holder {
  position:absolute;
  left: 25%;
  top: 40%;
  -webkit-transform: translate(-50%, -50%);
          transform: translate(-50%, -50%);
  text-align: center;
}

#city-name {
  font-family: "Courier New";
  font-size: 30px;
  font-weight: bold;
  color: #fff;
}

#icon {
  width:50%;
}

#main{
  width: 100%;
  height: 100%;
  position: relative;
}

.city-icon {
  height: 80%;
  width: 50%;
  border-bottom-left-radius: 25px;
  background-color: #FFC107;
}

.temperature {
  position: absolute;
  left: 50%;
  top:0%;
  height: 40%;
  width: 50%;
  background-color: #9C27B0;
}

.humidity {
  height: 40%;
  width: 50%;
  position:absolute;
  left:50%;
  top:40%;
  border-bottom-right-radius: 25px;
  background-color: #E91E63;
}

#search-btn {
  width: 40px;
  height:40px;
  color: #eee;
}

#search-txt {
  color: red;
  height:30px;
  border-radius: 10px;
  border-style:none;
  outline:none;
  padding-right:1px;
  padding-left:1px;
  text-align:center;
}

.search {
  position: absolute;
  left: 50%;
  top:50%;
  -webkit-transform:translate(-50%,-50%);
          transform:translate(-50%,-50%);
}
```
There is only one point that needs our attention regarding the above code:
-	In order to centrally align the whole container, we first need to set the value of position as **absolute**, then left and top are set to 50%, and after that the container is translated towards left by half of its width and towards north by half of its height.

After saving the aforementioned files, the app would look like this:
![1.png](https://github.com/IsrarAwan/weather-application/blob/master/imgs/1.png)

The above app is divided into three sections:
-	The left (lemon coloured) section is meant to display the city name and the icon for the weather condition.
-	The upper right (purplish coloured) section is meant to display the temperature of the city.
-	The lower right (reddish) section is meant to display the humidity in the city.
-	The input **Enter City Name** works in the following two ways: you can type the city name and hit **Enter** using your keyboard, or the other way is that you can type the city name and click the **search** button to get the updates.


## Weather App JavaScript
Now the last file **index.js**, which we have added into our HTML script at the start, needs to be added. The code for the JavaScript file is given as follows:
```javascript

const appKey = "f24f40b1c24505685fce3b8acd0fcffc";

let searchButton = document.getElementById("search-btn");
let searchInput = document.getElementById("search-txt");
let cityName = document.getElementById("city-name");
let icon = document.getElementById("icon");
let temperature = document.getElementById("temp");
let humidity = document.getElementById("humidity-div");

searchButton.addEventListener("click", findWeatherDetails);
searchInput.addEventListener("keyup", enterPressed);

function enterPressed(event) {
  if (event.key === "Enter") {
    findWeatherDetails();
  }
}

function findWeatherDetails() {
  if (searchInput.value === "") {
  
  }else {
    let searchLink = "https://api.openweathermap.org/data/2.5/weather?q=" + searchInput.value + "&appid="+appKey;
   httpRequestAsync(searchLink, theResponse);
  }
 }

function theResponse(response) {
  let jsonObject = JSON.parse(response);
  cityName.innerHTML = jsonObject.name;
  icon.src = "http://openweathermap.org/img/w/" + jsonObject.weather[0].icon + ".png";
  temperature.innerHTML = parseInt(jsonObject.main.temp - 273) + "°";
  humidity.innerHTML = jsonObject.main.humidity + "%";
}

function httpRequestAsync(url, callback)
{
  console.log("hello");
    var httpRequest = new XMLHttpRequest();
    httpRequest.onreadystatechange = () => { 
        if (httpRequest.readyState == 4 && httpRequest.status == 200)
            callback(httpRequest.responseText);
    }
    httpRequest.open("GET", url, true); // true for asynchronous 
    httpRequest.send();
}
```
Following are the important properties and methods of the aforementioned code:
-	appKey: App Key is required to get the Weather updates from OpenWeatherMap.
-	The format of the URL for the HTTP request is as follows: "https://api.openweathermap.org/data/2.5/weather?q=" + searchInput.value + "&appid="+appKey
-	In order to parse the JSON response getting from OpenWeatherMap API, **JSON.parse** method is used.
The rest of the code is self-explanatory! Now it’s time to see the DEMO of the Weather App!

## Demo
![Demo.gif](https://github.com/IsrarAwan/weather-application/blob/master/imgs/Demo.gif)

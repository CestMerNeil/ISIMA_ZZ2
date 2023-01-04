# TP 1

We will be using an identity services that is used to register user and create session for them.

## Get Started

* Read the code and understand it
* Run the application
* Create a Session using a POST to "/sessions"

## REST API

* Make the session creation Idempotent
* Return a 4xx when the user is not found
* Return a 4xx when the password doesn't match

## Build docker images

Compile code:

`./mvnw package`

Run the package application:

`java -jar target/tp1-0.0.1-SNAPSHOT.jar`

Package docker image:

`docker build -t modernarchi .`


## Scale the application

* Run three instance of the application on port 8080, 8081, 8082
* Run a loadbalancer in front of it

## Show the application is not Stateless

* Create multiple session
* And fail to access the profile

## Install a shared cache

* Install Redis
* Test it in the command line

## Use the cache in the application

* Adapt the code to use Redis

## Show the application is now Stateless

* Run the application in cluster mode
* Create a session and access it

## Bonus

* Hash the password
* Introduce a salt
* With encryption get rid of the cache

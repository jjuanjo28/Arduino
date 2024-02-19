

import * as firebase from 'firebase-admin';

const firebaseConfig = {
  apiKey: "AIzaSyBJUUYBsmItZMXOdaKGFYbMjbEnPUkWEHY",
  authDomain: "cultivo-c71e7.firebaseapp.com",
  databaseURL: "https://cultivo-c71e7-default-rtdb.firebaseio.com",
  projectId: "cultivo-c71e7",
  storageBucket: "cultivo-c71e7.appspot.com",
  messagingSenderId: "475243137677",
  appId: "1:475243137677:web:2d676fbe91d88243ccb0c4"
};


// Initialize Firebase
const base = firebase.initializeApp(firebaseConfig)
//console.log("soy base:",base)


export default {
  base
 
}


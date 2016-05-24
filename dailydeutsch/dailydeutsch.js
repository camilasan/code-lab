function makeRequest() {
  //console.log('makeRequest***********');
  var request = gapi.client.plus.activities.search({
    'query': 'dailydeutsch'
  });
  request.then(function(response) {
    //console.log(response.result);
  }, function(reason) {
    //console.log('Error: ' + reason.result.error.message);
  });
}

function init() {
  //console.log('INIT******');
  gapi.client.setApiKey(process.env.GOOGLE_PLUS);
  gapi.client.load('plus', 'v1').then(makeRequest);
}

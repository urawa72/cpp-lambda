#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/CreateTableRequest.h>
#include <aws/dynamodb/model/KeySchemaElement.h>
#include <aws/dynamodb/model/ProvisionedThroughput.h>
#include <aws/dynamodb/model/ScalarAttributeType.h>
#include <iostream>

// see
// https://docs.aws.amazon.com/sdk-for-cpp/v1/developer-guide/examples-dynamodb-tables.html
int main() {
  Aws::SDKOptions options;

  Aws::InitAPI(options);
  {
    const Aws::String table("SampleTable");
    const Aws::String region("ap-northeast-1");

    Aws::Client::ClientConfiguration clientConfig;
    if (!region.empty())
      clientConfig.region = region;
    Aws::DynamoDB::DynamoDBClient dynamoClient(clientConfig);

    Aws::DynamoDB::Model::CreateTableRequest req;

    Aws::DynamoDB::Model::AttributeDefinition haskKey;
    haskKey.SetAttributeName("Name");
    haskKey.SetAttributeType(Aws::DynamoDB::Model::ScalarAttributeType::S);
    req.AddAttributeDefinitions(haskKey);

    Aws::DynamoDB::Model::KeySchemaElement keyscelt;
    keyscelt.WithAttributeName("Name").WithKeyType(
        Aws::DynamoDB::Model::KeyType::HASH);
    req.AddKeySchema(keyscelt);

    Aws::DynamoDB::Model::ProvisionedThroughput thruput;
    thruput.WithReadCapacityUnits(5).WithWriteCapacityUnits(5);
    req.SetProvisionedThroughput(thruput);

    req.SetTableName(table);

    const Aws::DynamoDB::Model::CreateTableOutcome &result =
        dynamoClient.CreateTable(req);
    if (result.IsSuccess()) {
      std::cout << "Table "
                << result.GetResult().GetTableDescription().GetTableName()
                << " created!" << std::endl;
    } else {
      std::cout << "Failed to create table: " << result.GetError().GetMessage();
    }
  }
  Aws::ShutdownAPI(options);
  return 0;
}
